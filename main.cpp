/**
   * main
   *
   * @author       Tomas Hagos
   * @version      March 2, 2024
   *
   * REMARKS: To get command line arguments and run the simulation.
   */

#include <iostream>
#include "Simulation.h"
#include "OneWaitingLineSimulation.h"
#include "ExpressLaneSimulation.h"


int main(int argc, char *argv[])
{
    if(argc >=3)
    {
        fstream file(argv[1]);

        if(file.is_open())
        {
            Simulation* sim;

            if(*argv[2] == '1')
            {
                sim = new ExpressLaneSimulation(file);
            }
            else
            {
                sim = new OneWaitingLineSimulation(file);
            }

            //run simulation
            sim->run_simulation();

            file.close(); // close file

            //delete allocated memory for simulation
            delete sim;
        }
        else
        {
            cout << "Error! File could not be opened!" << endl;
        }

    }
    else
    {
        cout << "Error! Please provide sufficient command line arguments"<<endl;
        cout << "In this format: program_name textfile (1 or 2)" << endl;
    }

    cout << "End of Program" << endl;

    return 0;
}
