// OrderBook.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <map>	
#include <boost/optional/optional.hpp>

class OrderBook
{
	std::map<float, int> bids, asks;
	void add(float price, int amount, bool bid);
	void remove(float price, int amount, bool bid);
public:
	struct BidAsk {
		typedef boost::optional<std::pair<int, int>> Entry;
		Entry bid, ask;
		boost::optional<int> spread() const;
	};

	bool is_empty() const;
	void add_bid(float price, int amount);
	void add_ask(float price, int amount);
	void remove_bid(float price, int amount);
	void remove_ask(float price, int amount);
	void refill(const std::map<float, int>& bids, const std::map<float, int>& asks);

	BidAsk get_bid_ask() const;
	BidAsk get_bid_ask_skip(int amount) const;

	friend std::ostream& operator<<(std::ostream& os, const OrderBook& book);
};