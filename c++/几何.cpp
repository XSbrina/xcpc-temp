#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

//判断点是否在多边形内部

// 判定点 P 是否在多边形 poly 内部
// 返回值：1 表示在内部，0 表示在外部，-1 表示在边界上
int pointInPolygon(Point P, const vector<Point>& poly) {
    int n = poly.size();
    bool inside = false;
    for (int i = 0; i < n; i++) {
        Point p1 = poly[i];
        Point p2 = poly[(i + 1) % n]; // 下一个顶点，自动闭合
        // 1. 判断点 P 是否直接在边 p1-p2 上
        double cross = (p2.x - p1.x) * (P.y - p1.y) - (p2.y - p1.y) * (P.x - p1.x);
        if (abs(cross) < 1e-9) { // 向量共线
            if (P.x >= min(p1.x, p2.x) && P.x <= max(p1.x, p2.x) &&
                P.y >= min(p1.y, p2.y) && P.y <= max(p1.y, p2.y)) {
                return -1; // 在边界上
                }
        }
        // 2. 射线法计算交点（利用下闭上开原则避免重复计算顶点）
        bool cond1 = (p1.y <= P.y) && (P.y < p2.y);
        bool cond2 = (p2.y <= P.y) && (P.y < p1.y);
        if (cond1 || cond2) {
            // 计算射线与线段 p1-p2 的交点 x 坐标
            double intersect_x = p1.x + (P.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
            if (intersect_x > P.x) {
                inside = !inside; // 每检测到一个交点，状态翻转一次
            }
        }
    }
    return inside ? 1 : 0;
}

//判断两线段是否相交

// 计算向量 (p1 - p0) 与 (p2 - p0) 的二维叉乘
double cross(Point p0, Point p1, Point p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

// 标准线段相交判定
bool isIntersect(Point A, Point B, Point C, Point D) {
    // 1. 快速排斥实验
    if (max(A.x, B.x) < min(C.x, D.x) ||
        max(C.x, D.x) < min(A.x, B.x) ||
        max(A.y, B.y) < min(C.y, D.y) ||
        max(C.y, D.y) < min(A.y, B.y)) {
        return false;
        }

    // 2. 跨立实验
    double c1 = cross(A, B, C); // AC x AB
    double c2 = cross(A, B, D); // AD x AB
    double c3 = cross(C, D, A); // CA x CD
    double c4 = cross(C, D, B); // CB x CD

    return (c1 * c2 <= 0) && (c3 * c4 <= 0);
}