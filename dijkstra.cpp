#include<iostream>
using namespace std;
#define INFINITY 9999

class DJK{
    int graph[10][10];
    int n;
public:
    DJK(){
        cout<<"Enter the no of cities: ";
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                graph[i][j]=0;
    }

    void getdata();
    void display();
    void findRoute();
};

void DJK::getdata(){
    cout<<"Enter the distances between cities: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<"Enter the distance between "<<i+1<<" and "<<j+1<<" : ";
            cin>>graph[i][j];
            graph[j][i]=graph[i][j];
        }
    }
}

void DJK::display(){
    cout<<"\nThe distances between cities are "<<endl<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void DJK::findRoute(){
    int cost[n][n];
    int dist[n],pred[n],visited[n];
    int count=0,minDistance=0;

    int startCity,nextCity,endCity;
    cout<<"Enter the startcity: ";
    cin>>startCity;
    cout<<"Enter the endCity: ";
    cin>>endCity;
    startCity--;
    endCity--;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=graph[i][j];
        }
    }

    for(int i=0;i<n;i++){
        dist[i]=cost[startCity][i];
        pred[i]=startCity;
        visited[i]=0;
    }
    dist[startCity]=0;
    visited[startCity]=1;
    count++;

    while(count < n-1){
        minDistance=INFINITY;

        for(int i=0;i<n;i++){
            if(dist[i] < minDistance && !visited[i] ){
                minDistance=dist[i];
                nextCity=i;
            }
        }
        visited[nextCity]=1;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(minDistance+cost[nextCity][i] < dist[i]){
                    dist[i]=minDistance+cost[nextCity][i];
                    pred[i]=nextCity;
                }
            }
        }
        count++;
    }
    cout<<"The shortest path between "<<startCity+1<<" and "<<endCity+1<<" is "<<dist[endCity]<<endl;
    cout<<"and the route is: "<<endl;
    int j=endCity;
    cout<<endCity+1;
    do{
        j=pred[j];
        cout<<"<--"<<j+1;
    }
    while(j!=startCity);
}

int main(){
    DJK d;
    d.getdata();
    d.display();
    d.findRoute();
}
