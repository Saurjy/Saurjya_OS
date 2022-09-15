#include <iostream>
#include <queue>
#include <stdlib.h>

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
        int i , j = 0 , n , ts = 2 , completed = 0 ,temp;
        float Turn_time = 0 , wait_time = 0;
        cin >> n;
        struct process p[n];
        cin >> ts;
        queue<int> programs;
        
        /*Structure Initialisation by Taking User Input 
        in the format of Burst Time --- Arrival Time*/
        
        for(i = 0 ; i < n ; i++){
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
                    programs.push(p[i].p_id);
                    /*Push Current Process if 
                    current process has arrived*/
                else if(p[i].Completed != 1 && p[i].arrival_time > j)
                    j++;
                    /*If Current timeline has no work wait / skip time*/
                else
                    exit(0);//This condition should not be possible
            }
            while(!programs.empty()){
                temp = programs.front();
                programs.pop();
                /*Checks if the current program 
                can be executed withing Time Slice*/
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
        wait_time = wait_time + p[i].wait_time;
        Turn_time = Turn_time + p[i].Exttime-p[i].arrival_time;
    }
    for(i = 0 ; i < n ; i++)
    		cout << p[i].p_id << " Wait Time -> " << p[i].wait_time << " Ext_time " <<  p[i].Exttime <<"\n";
    /*Print Total Wait time*/
    wait_time = wait_time/n;
    Turn_time = Turn_time/n;
    std::cout.precision(3);
    std::cout << wait_time <<" " << Turn_time << std::endl;
    //cout << wait_time << " " << Turn_time;
}
