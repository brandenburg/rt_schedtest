/*    rt_density-test
 *      
 *    Youcef A. Benabbas.
 */
#include "cmdlparser.h"
#include "taskset.hpp"
#include "overhead.hpp"
#include "densitytest.hpp"
#include "schedtestparam.hpp"


int main(int argc, char **argv) {

  TaskSet *taskSet;
  Overhead *overhead;
  DensityTest densityTest;  
  SchedTestParam *schedTestParam;
  CmdlParser cmdlParser(argc, argv);    

  overhead = Overhead::getInstance();
  taskSet = TaskSet::getInstance();
  schedTestParam = SchedTestParam::getInstance();

  densityTest.setTaskSet(taskSet);
  densityTest.setOverhead(overhead);

  schedTestParam->initSchedTestParam();
  schedTestParam->setParameters(cmdlParser);
  schedTestParam->getSchedTestParam();

  overhead->updateAllOverheads(schedTestParam);
  
  taskSet->updateAllTasks(schedTestParam);

  taskSet->setParameters(cmdlParser);
  overhead->setParameters(cmdlParser);

  densityTest.makeSchedTest();
  return 0;
}
