// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}
void Train::addCage(bool light) {
	if (!first) {
		first = new Cage;
		first->light = light;
		first->next = nullptr;
		first->prev = nullptr;
	} else if (first->next == nullptr) {
		Cage* item = new Cage;
		item->light = light;
		item->prev = first;
		item->next = first;
		first->next = item;
		first->prev = item;
	} else {
		Cage* item = new Cage;
		item->light = light;
		item->prev = first->prev;
		first->prev->next = item;
		item->next = first;
		first->prev = item;
	}
}
int Train::getLength(){
	int lenght = 0;
	int curStep = 0;
	Cage* item = first;
	if (!item->light) {
		item->light = true;
	}
	while (true) {
		while (true) {
			item = item->next;
			curStep++;
			countOp++;
			if (item->light) {
				item->light = 0;
				break;
			}
		}
		lenght = curStep;
		while (curStep != 0) {
			item = item->prev;
			countOp++;
			curStep--;
		}
		if (!item->light)
			return lenght;
	}
}
int Train::getOpCount() {
	return countOp;
}

