//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
	//생성자, 소멸자
	shared_mut::shared_mut() {
		_mgr = new mgr();
	}
	shared_mut::shared_mut(const shared_mut& s){
		_mgr = s._mgr;
		increase();
	}
	shared_mut::shared_mut(Object* _obj) {
		_mgr = new mgr(_obj);
	}
	shared_mut::~shared_mut() {
		release();
	}
	void shared_mut::increase() {
		_mgr->count++;
	}
	void shared_mut::release() {
		_mgr->count--;
		_mgr->~mgr();
		this->_mgr = new mgr();
		if (_mgr->count == 0) {
			delete _mgr;
			this->_mgr = new mgr();
		}
	}
	Object* shared_mut::get() const {
		if (_mgr == nullptr) 
			return nullptr;
		else 
			return _mgr->ptr;
		
	}
	int shared_mut::count() {
		return _mgr->count;
	}
	shared_mut shared_mut:: operator+(const shared_mut& shared) {
		int tmp = this->get()->get() + shared.get()->get();
		return  shared_mut(new Object(tmp));
	}
	shared_mut shared_mut:: operator-(const shared_mut& shared){
		int tmp = this->get()->get() - shared.get()->get();
		return shared_mut(new Object(tmp));
	}

	shared_mut shared_mut:: operator*(const shared_mut& shared){
		int tmp = this->get()->get() * shared.get()->get();
		return shared_mut(new Object(tmp));
	}

	shared_mut shared_mut:: operator/(const shared_mut& shared){
		int tmp = this->get()->get() / shared.get()->get();
		return shared_mut(new Object(tmp));
	}

	Object* shared_mut::operator->() {
		return get();
	}
	shared_mut& shared_mut::operator=(const shared_mut& r) {
		this->release();
		int val = r._mgr->ptr->get();
		this->_mgr = new mgr(val);
		this->increase();
		return *this;
	}
} // end of namespace ptr
