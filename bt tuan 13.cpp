#include <iostream>
#include <string>
using namespace std;

struct sanPham {
    string maSP;
    string tenSP;
    int soLuong;
    float donGia;
};

struct Node {
    int maKH;                  
    sanPham* danhsachSP;      
    int soLuongSP;             
    float tongTien;            
    Node* next;                
};

struct Queue {
    Node* front;               
    Node* rear;                
};

double calculateTotalRevenue(Queue& q) {
    double total = 0;
    Node* current = q.front;
    while (current != nullptr) {
        for (int i = 0; i < current->soLuongSP; i++) {
            total += current->danhsachSP[i].soLuong * current->danhsachSP[i].donGia;
        }
        current = current->next;
    }
    return total;
}

int countProductSold(Queue& q, const string& productName) {
    int count = 0;
    Node* current = q.front;
    while (current != nullptr) {
        for (int i = 0; i < current->soLuongSP; i++) {
            if (current->danhsachSP[i].tenSP == productName) {
                count += current->danhsachSP[i].soLuong;
            }
        }
        current = current->next;
    }
    return count;
}
