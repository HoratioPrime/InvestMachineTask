// OrderBook.cpp : Defines the entry point for the application.
//

#include "OrderBook.h"

void OrderBook::add(float price, int amount, bool bid)
{
	if (bid)
	{
		bids[price] += amount;
	}
	else
	{
		asks[price] += amount;
	}
}

void OrderBook::remove(float price, int amount, bool bid)
{
	auto& table = bid ? bids : asks;
	auto it = table.find(price);
	if (it != table.end())
	{
		it->second -= amount;
		if (it->second == 0)
		{
			table.erase(it);
		}
	}
}

bool OrderBook::is_empty() const {
	return bids.empty() && asks.empty();
}

void OrderBook::add_bid(float price, int amount)
{
	add(price, amount, true);
}

void OrderBook::add_ask(float price, int amount)
{
	add(price, amount, false);
}

void OrderBook::remove_bid(float price, int amount)
{
	remove(price, amount, true);
}

void OrderBook::remove_ask(float price, int amount)
{
	remove(price, amount, false);
}

BidAsk OrderBook::get_bid_ask() const
{
	BidAsk result;
	auto best_bid = bids.rbegin();
	if (best_bid != bids.rend())
	{
		result.bid = *best_bid;
	}
	auto best_ask = asks.begin();
	if (best_ask != bids.end())
	{
		result.ask = *best_ask;
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const OrderBook& book)
{
	if (book.is_empty())
	{
		os << "ORDER BOOK EMPTY";
		return os;
	}
	for (auto it = book.asks.rbegin(); it != book.asks.rend(); ++it)
	{
		os << it->first << "\t" << it->second << std::endl;
	}
	os << std::endl;
	for (auto it = book.bids.rbegin(); it != book.bids.rend(); ++it)
	{
		os << it->first << "\t" << it->second << std::endl;
	}
	return os;
}

boost::optional<int> OrderBook::BidAsk::spread() const
{
	boost::optional<int> result;
	if (bid.is_initialized() && ask.is_initialized())
	{
		result = ask.get().first - bid.get().first;
	}
	return result;
}
