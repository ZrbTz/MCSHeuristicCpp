#include <string>
#include <vector>

struct TestDescription{
    std::string test_name;
    bool vertex_labeled;
    bool directed;
    bool connected;
    bool edge_labeled;
    float timeout;
    std::string node_heuristic;
};

class Test{
public:
    TestDescription td;
    float total_time;
    int recursions;
    std::vector<std::tuple<int, int, int>> milestones;
    std::vector<std::pair<int, int>> solution;
};