#pragma once
#include <vector>
#include <algorithm>
#include "Observer.h"
class Subject {
	public:
		Subject() {};
		virtual ~Subject() {};
		void attach(Observer& o) { observers.push_back(&o); };
		void detach(Observer& o) {
			observers.erase(std::remove(observers.begin(), observers.end(), &o));
		};
		void notify() {
			for (auto* o : observers) {
				o->update(*this);
			}
		};

	private:
		std::vector<Observer*> observers;
		


};