
#include "Bank.hpp"

#include <cstddef>
#include <memory>
#include <stdexcept>

#include "Account.hpp"
#include "Cheque.hpp"
#include "Deposits.hpp"
#include "Loan.hpp"
#include "Money.hpp"
#include "PersonalAccount.hpp"
#include "Ticket.hpp"

Bank::Bank(std::string time)
    : time(time) {}

void Bank::SetAccounts(std::vector<std::shared_ptr<Account>> accounts) {
    this->accounts = accounts;
}

int Bank::QueryAccount(std::string id) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i]->GetUser() == id) {
            return i;
        }
    }
    throw std::invalid_argument("no this user");
    return -1;
}

void Bank::Deposit(std::vector<Money> money, std::string id) {
    int index = QueryAccount(id);
    accounts[index]->Modify(Operation::Deposit, money[index].GetType(),
                            money[index].GetAmount());
}

std::vector<Money> Bank::Withdraw(Money money, std::string id) {
    std::vector<Money> uuu;
    int index = QueryAccount(id);
    accounts[index]->Modify(Operation::Withdraw, money.GetType(),
                            money.GetAmount());

    Money mm(money.GetType(), money.GetAmount());
    uuu.push_back(mm);
    return uuu;
} // return

std::vector<Money> Bank::Exchange(std::vector<Money> money,
                                  MoneyType exchangetype) {
    std::vector<Money> ex;
    for (auto m : money) {
        if (exchangetype == MoneyType::FS) {
            if (m.GetType() == MoneyType::FS) {
                ex.push_back(m);
            } else if (m.GetType() == MoneyType::OOP) {
                ex.push_back(Money(exchangetype, m.GetAmount() / 2));
            } else if (m.GetType() == MoneyType::OOTD) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 4 / 2));
            } else if (m.GetType() == MoneyType::PUA) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 6 / 2));
            } else if (m.GetType() == MoneyType::TWP) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 8 / 2));
            }
        }

        if (exchangetype == MoneyType::OOP) {
            if (m.GetType() == MoneyType::FS) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 2));
            } else if (m.GetType() == MoneyType::OOP) {
                ex.push_back(m);
            } else if (m.GetType() == MoneyType::OOTD) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 4));
            } else if (m.GetType() == MoneyType::PUA) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 6));
            } else if (m.GetType() == MoneyType::TWP) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 8));
            }
        }

        if (exchangetype == MoneyType::OOTD) {
            if (m.GetType() == MoneyType::FS) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 2 / 4));
            } else if (m.GetType() == MoneyType::OOP) {
                // ex.push_back(m);
                ex.push_back(Money(exchangetype, m.GetAmount() / 4));
            } else if (m.GetType() == MoneyType::OOTD) {
                ex.push_back(m);
            } else if (m.GetType() == MoneyType::PUA) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 6 / 4));
            } else if (m.GetType() == MoneyType::TWP) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 8 / 4));
            }
        }

        if (exchangetype == MoneyType::PUA) {
            if (m.GetType() == MoneyType::FS) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 2 / 6));
            } else if (m.GetType() == MoneyType::OOP) {
                ex.push_back(Money(exchangetype, m.GetAmount() / 6));
            } else if (m.GetType() == MoneyType::OOTD) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 4 / 6));
            } else if (m.GetType() == MoneyType::PUA) {
                ex.push_back(m);
            } else if (m.GetType() == MoneyType::TWP) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 8 / 6));
            }
        }

        if (exchangetype == MoneyType::TWP) {
            if (m.GetType() == MoneyType::FS) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 2 / 8));
            } else if (m.GetType() == MoneyType::OOP) {
                ex.push_back(Money(exchangetype, m.GetAmount() / 8));
            } else if (m.GetType() == MoneyType::OOTD) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 4 / 8));
            } else if (m.GetType() == MoneyType::PUA) {
                ex.push_back(Money(exchangetype, m.GetAmount() * 6 / 8));
            } else if (m.GetType() == MoneyType::TWP) {
                ex.push_back(m);
            }
        }
    }
    return ex;
}

std::vector<Money> Bank::Calculator(int amount, MoneyType type) {
    std::vector<Money> hhh;
    Money m(type, amount);
    hhh.push_back(m);
    return hhh;
}

std::shared_ptr<Ticket::Ticket>
Bank::MakeTicket(Ticket::TicketType type, std::string drawer, std::string payee,
                 MoneyType moneytype, int amount, std::string time) {
    std::shared_ptr<Ticket::Ticket> result;
    // float up = 0.0f;
    if (type == Ticket::TicketType::Cheque) {

    } else if (type == Ticket::TicketType::Deposits ||
               type == Ticket::TicketType::Loan) {
        // up = 0.3f;
        if (type == Ticket::TicketType::Deposits) {
            // Ticket::Ticket result(
            //     Ticket::Info{drawer, payee, amount, up, moneytype, type});
            ExchangeTicket(result);
        }
        if (type == Ticket::TicketType::Loan) {

            ExchangeTicket(result);
            // Ticket::Loan result(
            //     Ticket::Info{drawer, payee, amount, up, moneytype, type},
            //     "2025-01-10");
        }
    }
    return result;
}

void Bank::UpdateTime(std::string time) {
    if (time > this->time) {
        this->time = time;
    }
}

std::string Bank::GetTime() {
    return time;
}

void Bank::ExchangeTicket(std::shared_ptr<Ticket::Ticket> ticket) {
    auto info = ticket->GetTicketInfo();
    switch (info.ticketType) {
    case Ticket::TicketType::Cheque: {
        // TODO: Finish Cheque Effect.
        int p_idx = QueryAccount(info.payee);
        Withdraw(Money(info.moneyType, info.amount), info.drawer);

        if (accounts[p_idx]->GetAccountInfo() == AccountType::Personal) {
            std::shared_ptr<PersonalAccount> payee =
                std::dynamic_pointer_cast<PersonalAccount>(accounts[p_idx]);

        } else {
        }
        break;
    }
    case Ticket::TicketType::Loan: {
        // TODO: Finish Loan Effect.
        std::shared_ptr<Ticket::Loan> loan =
            std::dynamic_pointer_cast<Ticket::Loan>(ticket);

        break;
    }
    case Ticket::TicketType::Deposits: {
        // TODO: Finish Deposits Effect.
        std::shared_ptr<Ticket::Deposits> deposits =
            std::dynamic_pointer_cast<Ticket::Deposits>(ticket);
    }
    }
}
