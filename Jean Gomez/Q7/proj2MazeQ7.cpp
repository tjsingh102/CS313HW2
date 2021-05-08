#include <cstring>
#include <iostream>
#include <stack>
  
using namespace std;
  
#define N 4
#define M 5
  
class node {
public:
    int x, y;
    int dir;
  
    node(int i, int j)
    {
        x = i;
        y = j;
          
        // Initially direction 
        // set to 0
        dir = 0;
    }
};

void printpairs(pair<int, int> p) {
        cout << "("
         << p.first << ", "
         << p.second << ") ";
    
}

void printStack(stack<pair<int, int> > s) {
    while(!s.empty()) {
        printpairs(s.top());
        s.pop();
    }
}

void CorrectOrderPair(pair<int, int> p) {
    //here we just add on the top pair from our original stack to our new stack order
    //the stack order will flip the order of the pairs from our original stack we called in the while loop
    stack<pair<int,int> > order;
   
    order.push({p.first,p.second});

}

void passStack(stack<pair<int, int> > s) {
    stack<pair<int,int> > order;
    //stack order will have the pairs so that we can print the path of the maze starting from (0,0)

     while (!s.empty()) {
        CorrectOrderPair(s.top());
        order.push(s.top());
        s.pop();
    }
    printStack(order);
    cout << '\n';
    
}

  
bool visited[N][M];
  
bool findpath(int maze[N][M])
{
    // Initially starting at (0, 0).
    int i = 0;
    int j = 0;
    //stack keep track of the coordinate (x,y) pairs
    stack<pair<int, int> > pos;
    // stack of nodes that will also keep the direction of the node(pair)
    stack<node> n;
    //create a node named temp that will be set to the first cordinate (0,0)  
    node temp(i, j);//temp
    //push this node with coordinates and direction onto the stack s  
    n.push(temp);
  
    while (!n.empty()) {
        cout<<"here\n";
       
        temp = n.top();
        int d = temp.dir;// will check the top nodes direction then continue to increment it if we cannot find a path 
        i = temp.x, j = temp.y; //coordinates i & j are set to the top nodes coordiantes 
        cout<<d<<endl;
        // Increment the direction and
        // push the node in the stack again.
        temp.dir++;
        n.pop();
        n.push(temp);
  
        // if at the final coordinates end loop and print path
        if (i == N-1 and j == M-1) {
            node temp1(i, j);
            pos.push({i,j});
            n.push(temp1);
            passStack(pos);
            return true;
        }
  
        // north direction
        if (d == 0) {
            if (i - 1 >= 0 && maze[i - 1][j] && visited[i - 1][j]) {
                cout<<"N\n";
                node temp1(i - 1, j);
                visited[i - 1][j] = false;
                pos.push({i,j});
                n.push(temp1);
            }
        }
  
        // west direction
        else if (d == 1) {
            if (j - 1 >= 0 && maze[i][j - 1] && visited[i][j - 1]) {
                cout<<"W\n";
                node temp1(i, j - 1);
                visited[i][j - 1] = false;
                n.push(temp1);
                pos.push({i,j});
            }
        }
  
        // Check south direction 
        else if (d == 2) {
            if (i + 1 < N && maze[i + 1][j] && visited[i + 1][j]) {
                cout<<"S\n";
                node temp1(i + 1, j);
                visited[i + 1][j] = false;
                n.push(temp1);
                pos.push({i,j});
            }
        }
        // Check east direction
        else if (d == 3) {
            if (j + 1 < M && maze[i][j + 1] && visited[i][j + 1]) {
                cout<<"E\n";
                node temp1(i, j + 1);
                visited[i][j + 1] = false;
                n.push(temp1);
                pos.push({i,j});
            }
        }
  
        // if we cant get to the final coordinates of the maze we will exit and return false
        // set the path around us = to true(visited) then we'd break out of it
        else {
            cout<<"POP back to previous\n";
            visited[temp.x][temp.y] = true;
            n.pop();
            pos.pop();
        }
    }
    return false;
}
  
// Driver code
int main()
{
    // Initially setting the visited
    // array to true (unvisited)
    memset(visited, true, sizeof(visited));
      
    // Maze matrix
    int maze[N][M] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 1}
    };
  
    if (findpath(maze)) {
        cout << "Solution found" << '\n';
    }
    else
        cout << "There is no solution for this maze" << '\n';
          
    return 0;
}