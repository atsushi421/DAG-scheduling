#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "dagSched/DAGTask.h"
#include "dagSched/Taskset.h"
#include "dagSched/tests.h"

int main(int argc, char **argv) {

    if (REPRODUCIBLE) srand(1);
    else srand(time(NULL));

    std::string taskset_filename = "../demo/taskset.yaml";
    if (argc > 1)
        taskset_filename = argv[1];

    int n_proc = 4;
    if (argc > 2)
        n_proc = std::atoi(argv[2]);

    dagSched::Taskset taskset;
    size_t ext = taskset_filename.find("yaml");
    if (ext != std::string::npos)
        taskset.readTasksetFromYaml(taskset_filename);
    else
        taskset.readTasksetFromDOT(taskset_filename);

    std::cout << "Melani 2015 constrained (GP-FP-EDF): "
              << dagSched::GP_FP_EDF_Melani2015_C(taskset, n_proc) << std::endl;

    return 0;
}
