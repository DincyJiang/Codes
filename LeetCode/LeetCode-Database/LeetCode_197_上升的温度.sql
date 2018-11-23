-- 给定一个 Weather 表，编写一个 SQL 查询，来查找与之前（昨天的）日期相比温度更高的所有日期的 Id。

-- +---------+------------------+------------------+
-- | Id(INT) | RecordDate(DATE) | Temperature(INT) |
-- +---------+------------------+------------------+
-- |       1 |       2015-01-01 |               10 |
-- |       2 |       2015-01-02 |               25 |
-- |       3 |       2015-01-03 |               20 |
-- |       4 |       2015-01-04 |               30 |
-- +---------+------------------+------------------+
-- 例如，根据上述给定的 Weather 表格，返回如下 Id:

-- +----+
-- | Id |
-- +----+
-- |  2 |
-- |  4 |
-- +----+

-- 方法一：使用MySQL的函数Datadiff来计算两个日期的差值
SELECT
    w1.Id 
FROM
    Weather AS w1,
    Weather AS w2
WHERE
    w1.Temperature > w2.Temperature AND
    DATEDIFF(w1.RecordDate, w2.RecordDate) = 1; 

-- 方法二：使用了MySQL的TO_DAYS函数，用来将日期换算成天数
SELECT
    w1.Id
FROM
    Weather AS w1,
    Weather AS w2
WHERE
    w1.Temperature > w2.Temperature AND
    TO_DAYS(w1.RecordDate) = TO_DAYS(w2.RecordDate) + 1;

-- 方法三：使用Subdate函数，来实现日期减1
SELECT
    w1.Id
FROM
    Weather AS w1,
    Weather AS w2
WHERE
    w1.Temperature > w2.Temperature AND
    SUBDATE(w1.RecordDate, 1) = w2.RecordDate;