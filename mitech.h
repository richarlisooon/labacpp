#pragma once
#include <string>
class MiTech {
private:
	std::string _type;
	std::string _country;
	int _amount;
public:
	std::string type() const;
	std::string country() const;
	int amount() const;
	void settype(const std::string& type);
	void setcountry(const std::string& country);
	void setamount(const int& amount);
	
};