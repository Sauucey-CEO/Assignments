#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;
};

using SingularNode = Node;
using DoubleNode = Node;

SingularNode* createSingularList(int value) {
    SingularNode* newNode = new SingularNode;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

DoubleNode* createDoubleList(int value) {
    DoubleNode* newNode = new DoubleNode;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void appendSingular(int value, SingularNode *singularHead) {
    SingularNode* newNode = new SingularNode;
    newNode->value = value;
    newNode->next = nullptr;
    if (singularHead->next == nullptr) {
        singularHead->next = newNode;
    }
    else {
        SingularNode* P = singularHead;
        while (P->next != nullptr) {
            P = P->next;
        }
        P->next = newNode;
    }
}

void appendDouble(int value, DoubleNode* doubleHead) {
    DoubleNode* newNode = new DoubleNode;
    newNode->value = value;
    newNode->next = nullptr;
    if (doubleHead->next == nullptr) {
        doubleHead->next = newNode;
        newNode->prev = doubleHead;
    }
    else {
        DoubleNode* P = doubleHead;
        while (P->next != nullptr) {
            P = P->next;
        }
        P->next = newNode;
        newNode->prev = P;
    }
}

void makeSingularToCircular(SingularNode* head) {
    if (head->next == nullptr) return;
    SingularNode* P = head;

    while (P->next != nullptr) {
        P = P->next;
    }

    P->next = head;
}

void makeDoubleToCircular(DoubleNode* head) {
    if (head->next == nullptr) return;
    DoubleNode* P = head;

    while (P->next != nullptr) {
        P = P->next;
    }

    P->next = head;
    head->prev = P;
}

double getSingularAvg(SingularNode* head) {
    if (head->next == nullptr) return head->value;
    int count = 0;
    double sum = 0;
    SingularNode* P = head;
    while (P->next != nullptr) {
        sum += P->value;
        count++;
        P = P->next;
    }
    return sum / count;
}

double getDoubleAvg(DoubleNode* head) {
    if (head->next == nullptr) return head->value;
    int count = 0;
    double sum = 0;
    DoubleNode* P = head;
    while (P->next != nullptr) {
        sum += P->value;
        count++;
        P = P->next;
    }
    return sum / count;
}

double getSingularCircularAvg(SingularNode* head) {
    if (head->next == nullptr) return head->value;
    int count = 0;
    double sum = 0;
    SingularNode* P = head;
    do {
        sum += P->value;
        count++;
        P = P->next;
    } while (P->next != head);
    
    return sum / count;
}

double getDoubleCircularAvg(DoubleNode* head) {
    if (head->next == nullptr) return head->value;
    int count = 0;
    double sum = 0;
    DoubleNode* P = head;
    
    do {
        sum += P->value;
        count++;
        P = P->next;
    } while (P->next != head);

    return sum / count;
}

int getSingularAboveAvg(SingularNode* head) {
    if (head->next == nullptr) {
        cout << "Number above avg in singularList " << head->value << endl;
        return;
    }

    double avg = getSingularAvg(head);
    SingularNode* P = head;

    while (P != nullptr) {
        if (P->value > avg) {
            cout << "Number above avg in singularList " << P->value << endl;
            return P->value;
        }
        P = P->next;
    }
}

int getSingularBelowAvg(SingularNode* head) {
    if (head->next == nullptr) {
        cout << "Number above avg in singularList " << head->value << endl;
        return;
    }

    double avg = getSingularAvg(head);
    SingularNode* P = head;

    while (P != nullptr) {
        if (P->value < avg) {
            cout << "Number above avg in singularList " << P->value << endl;
            return P->value;
        }
        P = P->next;
    }
}

int getDoubleAboveAvg(DoubleNode* head) {
    if (head->next == nullptr) {
        cout << "Number above avg in singularList " << head->value << endl;
        return;
    }

    double avg = getDoubleAvg(head);
    DoubleNode* P = head;

    while (P != nullptr) {
        if (P->value > avg) {
            cout << "Number above avg in singularList " << P->value << endl;
            return P->value;
        }
        P = P->next;
    }
}

int getDoubleBelowAvg(DoubleNode* head) {
    if (head->next == nullptr) {
        cout << "Number above avg in singularList " << head->value << endl;
        return;
    }

    double avg = getDoubleAvg(head);
    DoubleNode* P = head;

    while (P != nullptr) {
        if (P->value < avg) {
            cout << "Number above avg in singularList " << P->value << endl;
            return P->value;
        }
        P = P->next;
    }
}

void connectSingularToDouble(SingularNode* singularHead, DoubleNode* doubleHead) {
    DoubleNode* P = doubleHead->prev;
    SingularNode* Q = singularHead;
    P->next = Q;
    Q->prev = P;
    while (Q->next != nullptr) {
        Q->next->prev = Q;
    }
}

void connectSingularToDoubleCircular(SingularNode* SingularCircularHead, DoubleNode* DoubleCircularHead) {

}

// free the memory
void freeSingular(SingularNode* head) {
    while (head != nullptr) {
        SingularNode* P = head;
        head = head->next;
        delete P;
    }
}

void freeDouble(DoubleNode* head) {
    while (head != nullptr) {
        DoubleNode* P = head;
        head = head->next;
        delete P;
    }
}

void freeSingularCircular(SingularNode* head) {
    if (head == nullptr) return;
    SingularNode* current = head->next;
    while (current != head) {
        SingularNode* P = current;
        current = current->next;
        delete P;
    }
    delete head;
}

void freeDoubleCircular(DoubleNode* head) {
    if (head == nullptr) return;
    DoubleNode* current = head->next;
    while (current != head) {
        DoubleNode* P = current;
        current = current->next;
        delete P;
    }
    delete head;
}

int main()
{
    // Creating the lists
    SingularNode* SingularListHead = createSingularList(1);
    appendSingular(2, SingularListHead);
    appendSingular(3, SingularListHead);
    appendSingular(4, SingularListHead);
    appendSingular(5, SingularListHead);
    DoubleNode* DoubleListHead = createDoubleList(1);
    appendDouble(2, DoubleListHead);
    appendDouble(3, DoubleListHead);
    appendDouble(4, DoubleListHead);
    appendDouble(5, DoubleListHead);
    SingularNode* SingularCircularHead = createSingularList(1);
    appendSingular(2, SingularCircularHead);
    appendSingular(3, SingularCircularHead);
    appendSingular(4, SingularCircularHead);
    appendSingular(5, SingularCircularHead);
    makeSingularToCircular(SingularCircularHead);
    DoubleNode* DoubleCircularHead = createDoubleList(1);
    appendDouble(2, DoubleCircularHead);
    appendDouble(3, DoubleCircularHead);
    appendDouble(4, DoubleCircularHead);
    appendDouble(5, DoubleCircularHead);
    makeDoubleToCircular(DoubleCircularHead);

    cout << "The avg of the first singular list is " << getSingularAvg(SingularListHead) << endl;
    cout << "The avg of the first double list is " << getDoubleAvg(DoubleListHead) << endl;
    cout << "The avg of the second singular circular list is " << getSingularCircularAvg(SingularCircularHead) << endl;
    cout << "The avg of the second double circular list is " << getDoubleCircularAvg(DoubleCircularHead) << endl;

    freeSingular(SingularListHead);
    freeDouble(DoubleListHead);
    freeSingularCircular(SingularCircularHead);
    freeDoubleCircular(DoubleCircularHead);

}