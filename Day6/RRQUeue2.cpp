#include <iostream>
#include <queue>
#include <stdlib.h>
#include <iomanip>
struct process{
    int arrival_time;
    int burst_time;
    int p_id;
    int RemainingTime;
    int Completed;
    int wait_time;
    int holdtime;
    int Exttime;
};

using namespace std;

int main(){
        int i , j = 0 , n = 2 , ts = 2 , completed = 0 ,temp;
        float Turn_time = 0 , wait_time = 0;
        cout << "Enter The Number of Processes and Time Slice\n";
        cin >> n;
        struct process p[n];
        cin >> ts;
        queue<int> Ready_Queue;

        /*Structure Initialisation by Taking User Input
        in the format of Burst Time --- Arrival Time*/
        /*
        p[0].burst_time = 3;
        p[0].arrival_time = 0;
        p[0].p_id = 0;
        p[0].RemainingTime = p[i].burst_time;
        p[0].Completed = 0;
        p[0].wait_time = 0;
        p[0].holdtime = p[i].arrival_time;
        p[0].Exttime = 0;
        p[1].burst_time = 7;
        p[1].arrival_time = 0;
        p[1].p_id = 1;
        p[1].RemainingTime = p[i].burst_time;
        p[1].Completed = 0;
        p[1].wait_time = 0;
        p[1].holdtime = p[i].arrival_time;
        p[1].Exttime = 0;
        */
        for(i = 0 ; i < n ; i++){
            cout << "Enter The Burst Time of Process P"<<i+1<<" and it's arrival time\n";
            cin >> p[i].burst_time;
            cin >> p[i].arrival_time;
            p[i].p_id = i;
            p[i].RemainingTime = p[i].burst_time;
            p[i].Completed = 0;
            p[i].wait_time = 0;
            p[i].holdtime = p[i].arrival_time;
            p[i].Exttime = 0;
        }
        while(completed != n){
            for(i = 0 ; i < n ; i++){
                if(p[i].Completed == 1 && p[i].arrival_time <= j)
                    continue;/*Next Process if current process is completed*/

                else if(p[i].Completed != 1 && p[i].arrival_time <= j)
                    Ready_Queue.push(p[i].p_id);
                    /*Push Current Process if
                    current process has arrived*/
                else if(p[i].Completed != 1 && p[i].arrival_time > j){
                      if(!Ready_Queue.empty())
                        continue;
                      else
                        j++;
                }
                    /*If Current timeline has no work wait / skip time*/
                else
                    exit(0);//This condition should not be possible
            }
            while(!Ready_Queue.empty()){
                temp = Ready_Queue.front();
                Ready_Queue.pop();
                if(p[temp].RemainingTime > ts){
                    p[temp].RemainingTime = p[temp].RemainingTime - ts;
                    p[temp].wait_time  = p[temp].wait_time + j - p[temp].holdtime;
                    j = j + ts;
                    p[temp].holdtime = j;
                }
                /*Checks if the current program
                is in it's last execution cycle*/
                else if(p[temp].RemainingTime <= ts){
                    p[temp].wait_time  = p[temp].wait_time + j - p[temp].holdtime;
                    j = j + p[temp].RemainingTime;
                    p[temp].RemainingTime = 0;
                    p[temp].holdtime = j;
                    p[temp].Completed = 1;
                    completed++;
                    p[temp].Exttime = j;
                }
            }
        }/*Calculate Total Wait and turnaround time*/
    for(i = 0 ; i < n ; i++){
        wait_time = wait_time+p[i].wait_time;
        Turn_time = Turn_time + (p[i].Exttime-p[i].arrival_time);
        //cout << p[i].wait_time<<"\n";
    }
    cout << "Process ID | Burst Time | Arrival Time | Wait Time | Exit Time | Turnaround Time \n";
    cout << "-----------|------------|--------------|-----------|-----------|-----------------\n";
    for(i = 0 ; i < n ; i++){
            cout << setw(5) << right << p[i].p_id <<setw(7) << right <<"|"<<setw(7) << right<< p[i].burst_time<<setw(6) << right <<"|"<<setw(8) << right<< p[i].arrival_time<<setw(7) << right <<"|"<< setw(6) << right <<p[i].wait_time <<setw(6) << right<<"|"<<setw(6) << right<< p[i].Exttime <<setw(6) << right<<"|"<<setw(8) << right<< p[i].Exttime-p[i].arrival_time<<"\n" ;
    }
    /*Print Total Wait time*/
    wait_time = wait_time/n;
    Turn_time = Turn_time/n;
    cout << "Total Wait Time = " <<wait_time << " Total TurnAround Time = " << Turn_time;
}
