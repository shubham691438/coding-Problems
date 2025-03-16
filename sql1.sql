-- Create Customer Details table
CREATE TABLE CustomerDetails (
    CusID INT PRIMARY KEY,
    CusName VARCHAR(255) NOT NULL,
    CusAge INT,
    CusContact VARCHAR(20)
);


-- Create Transaction Details table
CREATE TABLE TransactionDetails (
    CusID INT,
    TransactionID VARCHAR(255),
    AccountNo VARCHAR(20),
    Amount DECIMAL(10, 2),
    Date DATE,
    FOREIGN KEY (CusID) REFERENCES CustomerDetails(CusID)
);
