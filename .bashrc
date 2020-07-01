source ~/.bash/preexec.sh

export PROMPT_CMD=$HOME/github/prompt/prompt
export PROMPT_TIME_CMD=$HOME/github/prompt/prompt_time

PROMPT_DURATION=0
PROMPT_STATUS=0

prompt_cmd() {
  PROMPT_DURATION=${PROMPT_DURATION:-0} PROMPT_STATUS=${PROMPT_STATUS:-0} $PROMPT_CMD
}

prompt_preexec() {
  PROMP_START_TIME=$($PROMPT_TIME_CMD)
}

prompt_precmd() {
  export PROMPT_STATUS=$?
  if [[ -n "${PROMP_START_TIME+1}" ]]; then
    PROMPT_END_TIME=$($PROMPT_TIME_CMD)
    echo $PROMP_START_TIME $PROMPT_END_TIME
    PROMPT_DURATION=`expr $PROMPT_END_TIME - $PROMP_START_TIME`
    unset PROMPT_START_TIME PROMPT_END_TIME
    echo "SET $PROMPT_DURATION"
  else
    unset PROMPT_DURATION
  fi

  prompt_cmd
}

# pre-command-execution and post-command-execution to time the runtime
preexec_functions+=(prompt_preexec)
precmd_functions+=(prompt_precmd)

