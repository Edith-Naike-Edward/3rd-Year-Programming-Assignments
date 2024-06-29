//Robot Header

#ifndef ROBOT_H
#define ROBOT_H
#include 

struct movedBefore
{
    int x;
    int y;
};
class Robot
{
private:
    int x;
    int y;
    std::vector hereBefore;
public:
    Robot();
    Robot(int x, int y);
    movedBefore MoveRobot(bool Invalid[8], int * directions[2]);
};
#endif
// CPP

#include 
#include 
#include 
#include "Robot.h"

using namespace std;

void initMaze(char **maze, int height, int width, int obstacles, int RR, int RC);
void printMaze(char **maze, int height, int width);
void initwalls(bool *walls, char **maze, int &RR, int &RC, Robot &robot);
int getVisitedCount(char **maze, int height, int width);

struct coor {
    int x;
    int y;
};

// 1. Method Creating the Maze
void initMaze(char **maze, int height, int width, int obstacles, int RR, int RC) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = ' ';
        }
    }
    for (int i = 0; i < width; i++) {
        maze[0][i] = '+';
        maze[height - 1][i] = '+';
    }
    for (int i = 0; i < height; i++) {
        maze[i][0] = '+';
        maze[i][width - 1] = '+';
    }
    maze[RR][RC] = '+';
    vector obs;
    for (int i = 0; i < obstacles; i++) {
        bool found = true;
        while (found) {
            int x = rand() % (width - 2) + 1;
            int y = rand() % (height - 2) + 1;
            found = false;
            for (int j = 0; j < obs.size(); j++) {
                if ((obs[j].x == x && obs[j].y == y) || (y == RR && x == RC)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                coor newCoor;
                newCoor.x = x;
                newCoor.y = y;
                obs.push_back(newCoor);
                maze[y][x] = '+';
            }
        }
    }
}
// 2.Method
void printMaze(char **maze, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}


//3. Method
void initwalls(bool *walls, char **maze, int &RR, int &RC, Robot &robot) {
    int **directions = new int *[8];
    for (int i = 0; i < 8; i++) {
        directions[i] = new int[2];
    }
    directions[0][0] = RR - 1;
    directions[0][1] = RC - 1;
    directions[1][0] = RR - 1;
    directions[1][1] = RC + 0;
    directions[2][0] = RR - 1;
    directions[2][1] = RC + 1;
    directions[3][0] = RR + 0;
    directions[3][1] = RC - 1;
    directions[4][0] = RR + 0;
    directions[4][1] = RC + 1;
    directions[5][0] = RR + 1;
    directions[5][1] = RC - 1;
    directions[6][0] = RR + 1;
    directions[6][1] = RC + 0;
    directions[7][0] = RR + 1;
    directions[7][1] = RC + 1;

    for (int i = 0; i < 8; i++) {
        if (maze[directions[i][0]][directions[i][1]] == '+') {
            walls[i] = true;
        } else {
            walls[i] = false;
        }
    }
    movedBefore move = robot.MoveRobot(walls, directions);
    maze[RR][RC] = '.';
    RR = move.x;
    RC = move.y;
    maze[RR][RC] = 'X';

    for (int i = 0; i < 8; i++) {
        delete[] directions[i];
    }
    delete[] directions;
}

//4.Method
int getVisitedCount(char **maze, int height, int width) {
    int count = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == '.') {
                count++;
            }
        }
    }
    return count;
}


Robot::Robot() {
    this->x = 0;
    this->y = 0;}
Robot::Robot(int x, int y) {
    this->x = x;
    this->y = y;
    movedBefore Moving;
    Moving.x = x;
    Moving.y = y;
    hereBefore.push_back(Moving);}
movedBefore Robot::MoveRobot(bool Invalid[8], int *directions[2]) {
    for (int j = 0; j < 8; j++) {
        if (!Invalid[j]) {
            bool found = false;
            for (int i = 0; i < hereBefore.size(); i++) {
                if (directions[j][0] == hereBefore[i].x && directions[j][1] == hereBefore[i].y) {
                    found = true;}}
            if (!found) {
                movedBefore Moving;
                Moving.x = directions[j][0];
                Moving.y = directions[j][1];
                hereBefore.push_back(Moving);
                this->x = Moving.x;
                this->y = Moving.y;
                return Moving;}}}
    for (int i = hereBefore.size() - 1; i >= 0; i--) {
        if (hereBefore[i].x != x && hereBefore[i].y != y) {
            movedBefore Moving;
            Moving.x = hereBefore[i].x;
            Moving.y = hereBefore[i].y;
            return Moving;}}}
int main() {
    srand(static_cast(time(0)));
    int max = 0;
    int height = 0;
    int width = 0;
    int obstacles = 0;
    int RR = 0;
    int RC = 0;
    cout << "What is the height of the floor (whole number)?";
    cin >> height;
    height += 2;
    cout << "What is the width of the floor (whole number)?";
    cin >> width;
    width += 2;
    cout << "How many obstacles are there?";
    cin >> obstacles;
    cout << "what row does robot start on 1-" << height - 1 << "?";
    cin >> RR;
    cout << "what column does robot start on 1-" << width - 1 << "?";
    cin >> RC;
    char **maze = new char *[height];
    for (int i = 0; i < height; i++) {
        maze[i] = new char[width];}
    max = (height - 2) * (width - 2);
    Robot robot(RR, RC);
    initMaze(maze, height, width, obstacles, RR, RC);
    bool walls[8] = {false, false, false, false, false, false, false, false};
    printMaze(maze, height, width);
    double coverage = 0;
    int numberofMoves = 0;
    double efficiency = 0;

    while (coverage < .9) {
        initwalls(walls, maze, RR, RC, robot);
        printMaze(maze, height, width);
        // find coverage
        coverage = double(double(getVisitedCount(maze, height, width)) / double(max - obstacles));
        numberofMoves++; }
    // calculate efficiency then print coverage and efficiency
    efficiency = double(double(getVisitedCount(maze, height, width)) / double(numberofMoves));
    cout << "Coverage: " << coverage << endl;
    cout << "Efficiency: " << efficiency << endl;
    // free memory
    for (int i = 0; i < height; i++) {
        delete[] maze[i];
    }
    delete[] maze;
    system("pause");
    return 0;}