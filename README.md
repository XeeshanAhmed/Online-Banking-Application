# Banking Management System

This project implements a Banking Management System using object-oriented programming concepts such as abstraction, encapsulation, polymorphism, inheritance, association, aggregation, and composition. It provides functionalities for managing different types of clients and their accounts efficiently.

## Overview

The banking management system consists of three main components:

1. **User Client**: Represents individual users who can open single accounts.
2. **Company Client**: Represents companies whose CEOs can open shared accounts for their employees.
3. **Banking Employee**: Represents bank employees who manage client accounts and operations.

## Features

### Account Types

There are three types of accounts:
- **Bronze**: Daily Withdrawal Limit: 100,000 PKR
- **Gold**: Daily Withdrawal Limit: 500,000 PKR
- **Business**: Daily Withdrawal Limit: 20,000,000 PKR

### Transactions

The system supports the following transactions:
- Deposit
- Withdraw
- Transfer to another User Client

### User Client

- Users can open accounts by providing personal information.
- Upon approval, users are assigned a 16-digit card number and prompted to set a PIN.
- Users can deposit, withdraw, view balance, transaction history, and transfer funds.

### Company Client

- CEOs can open shared accounts for their companies.
- Employees can access the company account.
- Company clients can deposit, withdraw, view balance, transaction history, and transfer funds to user clients.

### Banking Employee

- Employees can log in and perform various administrative tasks.
- Tasks include viewing client accounts, approving/rejecting account applications, approving/rejecting loan requests, viewing transaction history, and freezing/closing accounts.

### Other Features

- Maintain transaction history in "transactions.txt".
- Maintain credit card information in "cards.txt".
- Implement fraud detection mechanisms.
- Implement PIN validation for transactions.

## Usage

1. Follow the prompts to navigate through the system.
2. Perform transactions as required.
3. Administer accounts and operations as a banking employee.

## Languages Used

- C++

