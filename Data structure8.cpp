#include <iostream>
#include <map>
using namespace std;

// Tham Lap Phong 20215449
template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {

    map<T, double> ans;
    for (auto v : a){
        double second = v.second;
        for (auto u : b){
            if (v.first == u.first){
                second = max(second, u.second);
                break;
            }
        }
        ans.insert({v.first, second});
    }
    for (auto v : b){
        double second = v.second;
        for (auto u : a){
            if (v.first == u.first){
                second = max(second, u.second);
                break;
            }
        }
        ans.insert({v.first, second});
    }
    return ans;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> ans;
    for (auto v : a){
        for (auto u : b){
            if (v.first == u.first){
                ans.insert({v.first, min(v.second, u.second)});
                break;
            }
        }
    }
    return ans;
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}
