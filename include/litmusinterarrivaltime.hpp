#ifndef LITMUS_INTERARRIVAL_TIME_HPP
#define LITMUS_INTERARRIVAL_TIME_HPP

#include "litmusschedulingtracerecord.hpp"

enum LitmusInterArrivalTimeState {
  
  IAT_WAIT_FOR_RELEASE_EVENT,
  IAT_WAIT_FOR_2ND_RELEASE_EVENT,
};
  
class LitmusInterArrivalTime : public LitmusSchedulingTraceRecord {

private:

  LitmusInterArrivalTimeState state;
  struct st_event_record  currentStEventRecord;

public:

  LitmusInterArrivalTime(ster_t);
  void check(struct st_event_record*);
  void updateTaskSet(lt_t inter_arrival_time, pid_t task_id);
};

#endif
