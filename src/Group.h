#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "VisualVisitor.h"

using namespace std;

// the group class allows for creation of linked lists that contain visitors, according to vip or not quality
class Group {
    private:
        //
        LinkedList<Visitor> members;
        static int groupId;
        bool vip;
        int membersCount = 0;

    public:

        Group(bool vip) : vip(vip) {
            //cout << "Group constructor" << endl;
            groupId++;
            if (vip) {
                for (int i = 0; i < 4; ++i) {
                    addVIPMember();
                }
            } else {
                for (int i = 0; i < 4; ++i) {
                    addRegMember();
                }
            }
        }

        int getGroupId() const {
            return groupId;
        }

        void addRegMember() {
            membersCount++;
            members.append(Visitor(groupId, false, false));
        }

        void addVIPMember() {
            membersCount++;
            members.append(Visitor(groupId, false, true));
        }

        Visitor getVisitor(int index) {
            return members.get(index);
        }

        void removeFirst() {
            members.deleteFirst();
        }


        int getGroupSize() const {
            return members.getLength();
        }

        bool isEmpty() const {
            return members.getLength() == 0;
        }
};

#endif  // GROUP_H
