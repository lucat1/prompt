#include <git2.h>
#include <stdio.h>

#include "../config.h"
#include "../prompt.h"

#if GIT_SEGMENT_BRANCH
git_reference *ref;
#endif

int initialized = 0;

void git_enter() {
  int init_err, repo_err;
#if GIT_SEGMENT_BRANCH
  int ref_err, branch_err;
  const char *branch_name;
#endif

  init_err = git_libgit2_init();
  if (init_err < 0)
    // if we cannot initialize libgit2 there's some serious proble
    // and the prompt should be notified
    fail("could not initialize libgit2");

  initialized = 1;

  // after initialization we attempt to open the cwd
  // to see if we are inside a repository
  git_repository *repo = NULL;
  repo_err = git_repository_open_ext(&repo, prompt_cwd, 0, NULL);
  if (repo_err != 0)
    // we can stop the execution here since we
    // clearly are not inside of a repository
    return;

#if GIT_SEGMENT_BRANCH
  // at this point we have instantiated the repo object
  // and we can pull the branch name
  ref_err = git_repository_head(&ref, repo);
  if(ref_err != 0)
    fail("could not get repository head reference");

  // get the branch name from the reference
  branch_err = git_branch_name(&branch_name, ref);
  if(branch_err != 0)
    fail("could not get branch name from reference");

  printf("%s ", branch_name);
#endif
}

void git_leave() {
  if(initialized)
    if(git_libgit2_shutdown() < 0)
      fail("could not *un*initialize libgit2");

#if GIT_SEGMENT_BRANCH
  if(ref != NULL)
    git_reference_free(ref);
#endif
}
