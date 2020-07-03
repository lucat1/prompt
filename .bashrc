source ~/.bash/preexec.sh

export PROMPT_CMD=$HOME/github/prompt/prompt
export PROMPT_TIME_CMD=$HOME/github/prompt/prompt_time

prompt_cmd() {
  PS1=$(PROMPT_DURATION=${PROMPT_DURATION:-0} PROMPT_STATUS=$? $PROMPT_CMD)
}

prompt_preexec() {
  if [ "$PREEXEC_READY" = "true" ]; then
    PREEXEC_READY=false
    PROMPT_START_TIME=$($PROMPT_TIME_CMD)
  fi
}

prompt_precmd() {
  if [[ $PROMPT_START_TIME ]]; then
    PROMPT_END_TIME=$($PROMPT_TIME_CMD)
    PROMPT_DURATION=`expr $PROMPT_END_TIME - $PROMPT_START_TIME`
    unset PROMPT_START_TIME PROMPT_END_TIME
  else
    unset PROMPT_START_TIME PROMPT_END_TIME PROMPT_DURATION
  fi
  PREEXEC_READY=true

  prompt_cmd
}

# pre-command-execution and post-command-execution to time the runtime
preexec_functions+=(prompt_preexec)
precmd_functions+=(prompt_precmd)
