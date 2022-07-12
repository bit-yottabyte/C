//Athavan Jesunesan

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <signal.h>
#include <pthread.h>
#include <iomanip>
#include <cmath>

using namespace std;

int NUMTHREADS;
volatile bool continuing;
volatile int occupied;
pthread_mutex_t lock; //Our mutual exclusion lock
int bestAns = 1000000; //the best minum so far
int bestX; //the x value corresponding to the best answer
int bestY; //the y value corresponding to the best answer


void* busywork(void* unnecessary);
void peek(int sig);
void interrupted(int sig);

int main() {
    pthread_t ct[NUMTHREADS];//our child threads
    continuing=true;
    std::cout<<"About to commence; PID: "<<getpid()<<std::endl;

    if (signal(SIGINT,interrupted)==SIG_ERR) {
        std::cout<<"Unable to change signal handler."<<std::endl;
        return 1;
    }
    int active = 1;
    while(active){
        std::cout<<"# of hill climbers: ";
        std::cin>>active;
        if(active==0) return 0;
        NUMTHREADS = active;
        for (int i=0;i<NUMTHREADS;i++) {
            pthread_mutex_lock(&lock);//reserve lock
            pthread_create(&ct[i], NULL, &busywork, NULL);
            occupied++;
            pthread_mutex_unlock(&lock);//release lock
        }

        //we don't need the mutex here, because we aren't changing occupied
        while (occupied>0){
            sleep(1);
        }
    }
    std::cout<<"Execution complete."<<std::endl;
}


void* busywork(void* unnecessary) {
    /*intializing variables*/
    int answer; //storing the calculations/'height'
    int x,y;
    int currentHeight;
    srand(time(NULL));
    int tempX, tempY; //these are our 'modifiers'
    x = (rand() %1024) - 512;
    y = (rand() %1024) - 512;
    int temp1, temp2; //these will be the 'height' compared
    /*this will run until we meet the interupt (ctrl+c)*/
    while (continuing) {
        srand(time(NULL));
        temp1 = (-(y+47))*sin(sqrt(abs(x/2+y+47))) - x*sin(sqrt(abs(x-y-47))); //calculating based off current x and y
        tempX = (rand() %10) - 5;
        tempY = (rand() %10) - 5;
        tempX+=x;
        tempY+=y;

        /*Setting the 'clamp' */
        if(tempX>512) tempX=512;
        if(tempY>512) tempY=512;
        if(tempX<-512) tempX=-512;
        if(tempX<-512) tempX=-512;
        temp2 = (-(tempY+47))*sin(sqrt(abs(tempX/2+tempY+47))) - tempX*sin(sqrt(abs(tempX-tempY-47))); //calculate based of the modified version

        /*this sections sets the climber to the better of the two versions */
        if(temp1>temp2){
            answer = temp1;
        }
        else{
            answer = temp2;
            x = tempX;
            y = tempY;
        }

        if(answer<bestAns){//change the best if this answer is better
            pthread_mutex_lock(&lock);
            bestAns = answer;
            bestX = x;
            bestY = y;
            pthread_mutex_unlock(&lock);
        }
    }

    pthread_mutex_lock(&lock);
    occupied--;
    std::cout<<"Exiting thread."<<std::endl;
    pthread_mutex_unlock(&lock);
}

void interrupted(int sig) {//closes the threads and outputs the values
    std::cout<<"\nComputations complete.\nHalting now..."<<std::endl;
    cout<< "The current minimum is "<<bestAns<<endl;
    cout<<"The corresponding X and Y values are: ["<<bestX<<","<<bestY<<"]"<<endl;
    continuing=false;
}
