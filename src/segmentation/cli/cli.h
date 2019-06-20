#ifndef __CLI_H__
#define __CLI_H__

#include <iostream>
#include "../../segmentation/algorithms/algorithms.h"
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstring>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;

enum algorithm_underlying_structure : int { array = 0, tree = 1, tree_pc = 2 };
typedef algorithm_underlying_structure algo_type;

void cli(int argc, char* argv[]);
void guide();
void segment_image_by_path(char* argv[]);
void segment_image_by_stdio(char* argv[]);
vector<int> do_segmentation(graph& G, algo_type algorithm, int n, int k, long long unsigned int& find_count, long long unsigned int& unite_count, long long unsigned int& cluster_count);
vector<int> do_segmentation_and_bench(graph& G, algo_type algorithm, int n, int k, long long unsigned int& find_count, long long unsigned int& unite_count, long long unsigned int& cluster_count);
long long unsigned int average(vector<chrono::nanoseconds>& deltas);

#endif