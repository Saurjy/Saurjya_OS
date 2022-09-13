#include <stdio.h>
#include <stdlib.h>
struct process{
	int burst_time;
	int arrival_time;
	int p_id;
	int wait_time;
	int RemainingTime;
	int Completed;
	int holdtime;
	int Exttime;
	int cxtswh;
	};
int main(){
	int i,j,k,n = 2,totaltime = 0 , flag = 0 , min = 99, curr = 1 , completed = 0 , wait_time = 0 ;
	float Turn_time = 0;
	scanf("%d",&n);
	struct process* p = malloc(n*(sizeof(struct process)));
	
	p[0].burst_time = 9; 
	p[0].arrival_time = 0;
	p[0].holdtime = 0;
	p[0].p_id = 0;
	p[0].RemainingTime = 9;
	p[0].wait_time = 0;
	p[0].Completed = 0;
	p[0].cxtswh = 0;
	
	p[1].burst_time = 2;
	p[1].arrival_time = 2;
	p[1].holdtime = 2;
	p[1].p_id = 1;
	p[1].RemainingTime = 2;
	p[1].wait_time = 0;
	p[1].Completed = 0;
	p[1].cxtswh = 0;
	
	/*p[2].burst_time = 5;
	p[2].arrival_time = 2;
	p[2].holdtime = 2;
	p[2].p_id = 2;
	p[2].RemainingTime = 5;
	p[2].wait_time = 0;
	p[2].Completed = 0;
	p[2].cxtswh = 0;
	
	p[3].burst_time = 1;
	p[3].arrival_time = 3;
	p[3].holdtime = 3;
	p[3].p_id = 3;
	p[3].RemainingTime = 1;
	p[3].wait_time = 0;
	p[3].Completed = 0;
	p[3].cxtswh = 0;
	
	p[4].burst_time = 6; 
	p[4].arrival_time = 9;
	p[4].holdtime = 9;
	p[4].p_id = 4;
	p[4].RemainingTime = 6;
	p[4].wait_time = 0;
	p[4].Completed = 0;
	p[4].cxtswh = 0;*/
	
	for(i = 0 ; i < n ; i++){
		scanf("%d %d",&p[i].burst_time, &p[i].arrival_time);
		p[i].holdtime = p[i].arrival_time;
		p[i].p_id = i;
		p[i].RemainingTime = p[i].burst_time;
		p[i].wait_time = 0;
		p[i].Completed = 0;
		p[i].cxtswh = 0;
	}
	
	for(i = 0 ; i < n ; i++){
		//printf("%d %d\n",p[i].burst_time, p[i].arrival_time);
		if(p[i].RemainingTime < min && p[i].arrival_time == 0){
			min = p[i].RemainingTime;
			curr = i;
		}
		totaltime=totaltime+p[i].burst_time;
	}
		
	//printf("Assuming the Arrival times in Ascending Order We get avg Waiting time = 6secs\n");
	
	for(i = 0 ; i < totaltime ; i++){
		min = 99;
		flag = curr;
		for(j = 0 ; j < n ; j++){
			if(p[j].Completed == 1)
				continue;
			else if(p[j].arrival_time > i)
				continue;
			else{
				if(p[j].RemainingTime < min){
					min = p[j].RemainingTime;
					curr = j;
				}
			}
		}
		if(p[flag].cxtswh == 0){
			p[flag].cxtswh = 1;
			p[flag].wait_time = p[flag].wait_time + i - p[flag].holdtime;
		}
		if(flag == curr && p[curr].RemainingTime != 0){
			p[curr].RemainingTime--;
			if(p[curr].RemainingTime == 0){
				p[curr].Completed = 1;
				p[curr].Exttime = i;
				completed++;
			}
			//printf("%d %d %d\n",flag,curr,i);
		}
		else if(flag != curr && p[curr].RemainingTime != 0){
			p[curr].RemainingTime--;
			//p[flag].wait_time = p[flag].wait_time + i - p[flag].holdtime;
			p[flag].holdtime = i;
			p[flag].cxtswh = 0;
			p[curr].cxtswh = 0;
			if(p[curr].RemainingTime == 0){
				p[curr].Exttime = i;
				p[curr].Completed = 1;
				completed++;
			}
			//printf("%d %d %d\n",flag,curr,i);
		}
		
		//printf("%d %d %d %d %d %d\n",p[curr].p_id,flag,curr,p[curr].RemainingTime,p[curr].wait_time,i+1);
		
	}
	
	for(i = 0 ; i < n ; i++){
		wait_time = wait_time + p[i].wait_time-1 ;
		Turn_time = Turn_time + p[i].Exttime-p[i].arrival_time+1;
		//printf("%d\n",p[i].wait_time-1);
		//printf("%d\n",p[i].Exttime-p[i].arrival_time+1);
		}
	printf("%d %.2f\n",wait_time/n,Turn_time/n);
	
}
