#ifndef MAP_H
#define MAP_H
#include <vector>
#include <QString>


using namespace std;

class Map
{
public:
    Map(int level);
    ~Map();

    void loadLevelFromFile(int level);
    vector<QString> *giveLevelLayout();

private:
    vector<QString> levelLayout_;
};

#endif // MAP_H
