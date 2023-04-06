#include <iostream>

using namespace std;

// Tek bağlı liste düğümü
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    // listenin ortasına kadar ilerleyen slow ve fast pointer'larını oluşturun
    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // listenin ikinci yarısını tersine çevirin
    ListNode *prev = nullptr, *cur = slow->next, *next = nullptr;
    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    // ikinci yarıyı ilerleyerek, ilk yarının elemanlarıyla karşılaştırın
    ListNode *p1 = head, *p2 = prev;
    while (p2 != nullptr) {
        if (p1->val != p2->val) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // listenin ikinci yarısını tekrar tersine çevirin ve geri dönün
    prev = nullptr, cur = prev, next = prev;
    while (p2 != nullptr) {
        next = p2->next;
        p2->next = prev;
        prev = p2;
        p2 = next;
    }
    slow->next = prev;

    return true;
}

int main() {
    // örnek bir bağlı liste oluşturun
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    // bağlı listenin palindrom olup olmadığını kontrol edin
    bool is_palindrome = isPalindrome(head);

    // sonucu yazdırın
    if (is_palindrome) {
        cout << "Bagli liste palindromdur." << endl;
    } else {
        cout << "Bagli liste palindrom degildir." << endl;
    }

    return 0;
}
