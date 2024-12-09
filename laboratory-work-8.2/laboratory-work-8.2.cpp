#include <iostream>
#include <algorithm>
#include <vector>
#include "DoublyLinkedList.h"
#include "FileFunctions.h"
#include "Deposit.h"

using namespace std;

bool sortByName(const Node* object_1, const Node* object_2)
{
    return object_1->data.name < object_2->data.name;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    if (argc < 2) {
        cerr << "Укажите имя файла в аргументах программы." << endl;
        return 1;
    }

    string file_name = argv[1];
    DoublyLinkedList list;
    vector<Deposit> data = read_data(file_name);

    for (const auto& deposit : data)
    {
        push_back(list, deposit);
    }

    vector<Node*> sort_vec;
    Node* current_node = list.head;
    while (current_node != nullptr)
    {
        sort_vec.push_back(current_node);
        current_node = current_node->next;
    }

    sort(sort_vec.begin(), sort_vec.end(), sortByName);

    DoublyLinkedList sorted_list;
    for (const auto& node : sort_vec)
    {
        push_back(sorted_list, node->data);
    }

    print_list(sorted_list);

    return 0;
}
