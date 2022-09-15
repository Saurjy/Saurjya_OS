// CPP code to illustrate Queue in
// Standard Template Library (STL)
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

// Print the queue
void showq(queue<int> gq)
{
	queue<int> g = gq;
	while (!g.empty()) {
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';
}

int main()
{
	int i , j = 0, n = 2, ts=2 ,timetotal = 0 , completed = 0 , temp ,size;
	float Turn_time = 0 , wait_time = 0;
	cin >> n;
	struct process p[n];
	queue<int> programs;
	//scanf("%d %d",&n,&ts);
	cin >> ts;
	for(i = 0 ; i < n ; i++){
		cin >> p[i].burst_time;
		cin >> p[i].arrival_time;
		p[i].RemainingTime = p[i].burst_time;
		p[i].p_id = i;
		p[i].Completed = 0;
		p[i].holdtime = p[i].arrival_time;
		p[i].Exttime = 0;
		p[i].wait_time = 0;
    	}
    	/*for(i = 0 ; i < n ; i++){
    		cout << p[i].burst_time;
		cout << p[i].arrival_time;
    	}*/
    	while(completed != n){
    		for(i = 0 ; i < n ; i++){
    			if(p[i].Completed == 1 && p[i].arrival_time <= j)
    				continue;
    			else if(p[i].arrival_time <= j && p[i].Completed != 1)
    				programs.push(p[i].p_id);
    			/*else if(p[i].arrival_time == 0 && p[i].Completed != 1)
    				programs.push(p[i].p_id);*/
    			else if(p[i].arrival_time > j && p[i].Completed != 1){
    				if(!programs.empty())
    					continue;
    				else
    					j++;	
    			}
    				
    			else
    				exit(0);
    			//cout << "A \n";
    		}
    		//cout << "B "<< j <<" \n";
    		while(!programs.empty()){
    			showq(programs);
    			//cout << programs.front() << " ----- " << programs.size() <<"\n";
    			temp = programs.front();
    			programs.pop();
    			if(p[temp].RemainingTime > ts){
    				p[temp].RemainingTime = p[temp].RemainingTime - ts;
    				p[temp].wait_time = p[temp].wait_time + (j - p[temp].holdtime);
    				//cout << p[temp].RemainingTime << "of" << temp <<"\n";
    				j = j + ts;
    				p[temp].holdtime = j;
    			}
    			else if(p[temp].RemainingTime <= ts){
    				p[temp].wait_time = p[temp].wait_time + (j - p[temp].holdtime);
    				j = j + p[temp].RemainingTime;
    				//cout << p[temp].RemainingTime << "of" << temp <<"\n";
    				p[temp].RemainingTime = 0;
    				p[temp].holdtime = j;
    				p[temp].Completed = 1;
    				completed++;
    				p[temp].Exttime = j;
    			}
    			//cout << "C \n";
    		}
    		//cout << "D \n";
    		/*for(i = 0 ; i < n ; i++){
    			if(p[i].RemainingTime == 0 && p[i].Completed != 1){
    				//cout << p[i].p_id << "Completed " << p[i].RemainingTime <<"\n";
    				p[i].Completed = 1;
    				completed++;
    				p[i].Exttime = p[i].holdtime;
    			}
    		}*/
    		//cout << "E\n";
    	}
    	for(i = 0 ; i < n ; i++)
    		cout << p[i].p_id << " Wait Time -> " << p[i].wait_time << " Ext_time " <<  p[i].Exttime <<"\n";

	return 0;
}

