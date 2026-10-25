# SQL 常见指令与使用方法笔记

> 适用对象：SQL 初学者\
> 示例默认使用常见的 MySQL 写法。不同数据库（MySQL、PostgreSQL、SQL
> Server、SQLite、Oracle）在部分函数、分页语法和数据类型上存在差异，使用时请以所用数据库的文档为准。

## 目录

1.  [SQL 是什么](#1-sql-是什么)
2.  [示例数据库](#2-示例数据库)
3.  [SQL 语句分类](#3-sql-语句分类)
4.  [数据库与数据表](#4-数据库与数据表)
5.  [增删改查：CRUD](#5-增删改查crud)
6.  [WHERE 条件筛选](#6-where-条件筛选)
7.  [排序与限制结果](#7-排序与限制结果)
8.  [聚合函数与分组](#8-聚合函数与分组)
9.  [多表查询与 JOIN](#9-多表查询与-join)
10. [子查询](#10-子查询)
11. [约束与索引](#11-约束与索引)
12. [视图](#12-视图)
13. [事务](#13-事务)
14. [常用函数](#14-常用函数)
15. [CASE 条件表达式](#15-case-条件表达式)
16. [WITH 公用表表达式](#16-with-公用表表达式)
17. [常见易错点](#17-常见易错点)
18. [速查表](#18-速查表)

------------------------------------------------------------------------

## 1. SQL 是什么

SQL（Structured Query
Language，结构化查询语言）是一种用于操作关系型数据库的语言。常见用途包括：

-   创建数据库和数据表。
-   插入、查询、修改、删除数据。
-   统计和汇总数据。
-   设置主键、外键、唯一性等约束。
-   控制事务，保证一组操作按预期完成。

### 一个最简单的例子

``` sql
SELECT name, age
FROM students
WHERE age >= 18;
```

含义：

1.  `SELECT name, age`：选择要显示的列。
2.  `FROM students`：从 `students` 表读取数据。
3.  `WHERE age >= 18`：只保留年龄大于或等于 18 的记录。

SQL
关键字通常不区分大小写，但表名、列名和字符串的大小写行为可能受数据库及其配置影响。为了易读，常将关键字大写、表名和列名使用小写。

## 2. 示例数据库

后面的例子主要使用两张表。

### students 学生表

    id name     age   class_id   score
  ---- ------ ----- ---------- -------
     1 Lin       18          1      92
     2 Wang      17          1      85
     3 Chen      19          2      76
     4 Zhao      18          2      92
     5 Sun       20       NULL      88

### classes 班级表

    id class_name
  ---- ------------
     1 Class A
     2 Class B
     3 Class C

说明：`NULL` 表示缺失或未知的值，不等同于数字 `0` 或空字符串 `''`。

## 3. SQL 语句分类

  ------------------------------------------------------------------------------------------------------
  分类                    常见指令                                用途
  ----------------------- --------------------------------------- --------------------------------------
  DDL（数据定义语言）     `CREATE`、`ALTER`、`DROP`、`TRUNCATE`   定义或调整数据库对象

  DML（数据操作语言）     `INSERT`、`UPDATE`、`DELETE`            新增、修改、删除数据

  DQL（数据查询语言）     `SELECT`                                查询数据

  DCL（数据控制语言）     `GRANT`、`REVOKE`                       管理权限（具体支持情况因数据库而异）

  TCL（事务控制语言）     `COMMIT`、`ROLLBACK`、`SAVEPOINT`       控制事务
  ------------------------------------------------------------------------------------------------------

## 4. 数据库与数据表

### 4.1 创建数据库

``` sql
CREATE DATABASE school;
```

在 MySQL 中可以指定字符集：

``` sql
CREATE DATABASE school
CHARACTER SET utf8mb4;
```

### 4.2 选择数据库

MySQL：

``` sql
USE school;
```

注意：`USE` 并不是所有数据库都支持的语法。例如 PostgreSQL
通常在连接时指定数据库。

### 4.3 创建数据表

``` sql
CREATE TABLE students (
    id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    age INT,
    class_id INT,
    score DECIMAL(5, 2)
);
```

常见数据类型：

  ----------------------------------------------------------------------------------
  类型                    含义                             示例
  ----------------------- -------------------------------- -------------------------
  `INT`                   整数                             `18`

  `DECIMAL(p, s)`         精确小数，适合金额等数值         `DECIMAL(8, 2)`

  `VARCHAR(n)`            可变长度字符串                   `VARCHAR(50)`

  `CHAR(n)`               定长字符串                       `CHAR(2)`

  `DATE`                  日期                             `'2026-10-25'`

  `DATETIME` /            日期时间，具体行为依数据库而异   `'2026-10-25 10:30:00'`
  `TIMESTAMP`                                              

  `BOOLEAN`               布尔值；底层表示因数据库而异     `TRUE`
  ----------------------------------------------------------------------------------

### 4.4 修改表结构：ALTER TABLE

添加列：

``` sql
ALTER TABLE students
ADD email VARCHAR(100);
```

修改列类型的语法依数据库而异。MySQL 示例：

``` sql
ALTER TABLE students
MODIFY COLUMN name VARCHAR(100);
```

删除列：

``` sql
ALTER TABLE students
DROP COLUMN email;
```

执行结构修改前，应确认数据是否需要保留，并注意可能产生的锁表或迁移影响。

### 4.5 删除数据库或表

``` sql
DROP TABLE students;
```

``` sql
DROP DATABASE school;
```

`DROP`
会删除数据库对象本身，通常也会删除其包含的数据。执行前应确认目标对象和备份情况。

### 4.6 清空表中数据

``` sql
TRUNCATE TABLE students;
```

`TRUNCATE`
通常用于快速清空整张表，但是否可回滚、是否重置自增值等行为取决于数据库。

与 `DELETE` 的区别：

-   `DELETE FROM students;`：按行删除数据，可以配合 `WHERE`
    只删部分记录。
-   `TRUNCATE TABLE students;`：清空整张表，不支持 `WHERE`。
-   `DROP TABLE students;`：删除整张表的结构及数据。

## 5. 增删改查（CRUD）

CRUD 是 Create、Read、Update、Delete 的缩写，即新增、查询、修改、删除。

### 5.1 INSERT：插入数据

指定列插入一条记录：

``` sql
INSERT INTO students (id, name, age, class_id, score)
VALUES (6, 'Liu', 18, 1, 90);
```

一次插入多条记录：

``` sql
INSERT INTO students (id, name, age, class_id, score)
VALUES
    (7, 'He', 17, 2, 81),
    (8, 'Wu', 19, 1, 95);
```

如果列允许 `NULL`
或具有默认值，可以不提供对应列；但应明确指定列名，避免依赖表的列顺序。

### 5.2 SELECT：查询数据

查询所有列：

``` sql
SELECT *
FROM students;
```

查询指定列：

``` sql
SELECT name, score
FROM students;
```

使用别名：

``` sql
SELECT name AS student_name, score AS exam_score
FROM students;
```

去除重复结果：

``` sql
SELECT DISTINCT class_id
FROM students;
```

`DISTINCT` 会对所选列组合去重。

### 5.3 UPDATE：修改数据

``` sql
UPDATE students
SET score = 95
WHERE id = 1;
```

同时修改多个列：

``` sql
UPDATE students
SET age = 19, score = 96
WHERE id = 1;
```

**重要：没有 `WHERE` 时，通常会修改表中的所有记录。**

执行更新前，可以先用相同条件执行 `SELECT`，确认目标行：

``` sql
SELECT *
FROM students
WHERE id = 1;
```

### 5.4 DELETE：删除数据

删除符合条件的记录：

``` sql
DELETE FROM students
WHERE id = 5;
```

删除所有记录：

``` sql
DELETE FROM students;
```

**重要：没有 `WHERE` 时，通常会删除表中所有记录。**
删除前应核对条件，并在重要数据操作前做好备份。

## 6. WHERE 条件筛选

### 6.1 比较运算符

  运算符         含义                    示例
  -------------- ----------------------- --------------
  `=`            等于                    `age = 18`
  `<>` 或 `!=`   不等于（`<>` 更通用）   `age <> 18`
  `>`            大于                    `score > 90`
  `<`            小于                    `score < 60`
  `>=`           大于或等于              `age >= 18`
  `<=`           小于或等于              `age <= 20`

``` sql
SELECT *
FROM students
WHERE score >= 90;
```

### 6.2 AND、OR、NOT

``` sql
SELECT *
FROM students
WHERE age >= 18 AND score >= 90;
```

``` sql
SELECT *
FROM students
WHERE age < 18 OR score >= 90;
```

``` sql
SELECT *
FROM students
WHERE NOT class_id = 1;
```

混用 `AND` 和 `OR` 时，建议使用括号明确优先级：

``` sql
SELECT *
FROM students
WHERE (age >= 18 AND score >= 90)
   OR class_id = 2;
```

### 6.3 BETWEEN：范围查询

``` sql
SELECT *
FROM students
WHERE age BETWEEN 18 AND 20;
```

`BETWEEN` 通常包含起点和终点，等价于：

``` sql
WHERE age >= 18 AND age <= 20
```

### 6.4 IN：匹配多个候选值

``` sql
SELECT *
FROM students
WHERE class_id IN (1, 2);
```

不在候选列表中：

``` sql
SELECT *
FROM students
WHERE class_id NOT IN (1, 2);
```

注意：如果 `NOT IN` 的列表包含
`NULL`，结果可能与直觉不同。处理可能包含空值的数据时要特别小心。

### 6.5 LIKE：模糊匹配

  通配符   含义
  -------- ----------------------------------
  `%`      任意长度的字符序列，包括零个字符
  `_`      任意单个字符

``` sql
-- 名字以 L 开头
SELECT * FROM students WHERE name LIKE 'L%';

-- 名字以 n 结尾
SELECT * FROM students WHERE name LIKE '%n';

-- 名字中包含 a
SELECT * FROM students WHERE name LIKE '%a%';
```

`LIKE` 的大小写敏感性取决于数据库、字符集和排序规则。

### 6.6 NULL 判断

错误写法：

``` sql
WHERE class_id = NULL
```

正确写法：

``` sql
SELECT *
FROM students
WHERE class_id IS NULL;
```

查询非空值：

``` sql
SELECT *
FROM students
WHERE class_id IS NOT NULL;
```

原因：`NULL` 表示未知或缺失，不能像普通值一样用 `=` 进行比较。

## 7. 排序与限制结果

### 7.1 ORDER BY：排序

升序：

``` sql
SELECT *
FROM students
ORDER BY score ASC;
```

降序：

``` sql
SELECT *
FROM students
ORDER BY score DESC;
```

多列排序：先按分数降序；分数相同时，再按年龄升序。

``` sql
SELECT *
FROM students
ORDER BY score DESC, age ASC;
```

`ASC` 是升序，`DESC` 是降序。若不写排序方向，通常默认升序。

### 7.2 LIMIT：限制返回行数

MySQL、PostgreSQL、SQLite 常见写法：

``` sql
SELECT *
FROM students
ORDER BY score DESC
LIMIT 3;
```

跳过前 3 行，再取 5 行：

``` sql
SELECT *
FROM students
ORDER BY score DESC
LIMIT 5 OFFSET 3;
```

分页查询通常需要稳定排序；如果排序列可能重复，可以再加唯一列，例如
`ORDER BY score DESC, id ASC`。

**方言提示：** SQL Server 常用 `TOP` 或 `OFFSET ... FETCH`；Oracle
等数据库也有自己的分页语法。

## 8. 聚合函数与分组

聚合函数将多行数据汇总为一个结果。

  函数              用途                       示例
  ----------------- -------------------------- ----------------
  `COUNT(*)`        统计行数                   `COUNT(*)`
  `COUNT(column)`   统计该列非 `NULL` 的数量   `COUNT(score)`
  `SUM(column)`     求和                       `SUM(score)`
  `AVG(column)`     求平均值                   `AVG(score)`
  `MAX(column)`     最大值                     `MAX(score)`
  `MIN(column)`     最小值                     `MIN(score)`

### 8.1 基本统计

``` sql
SELECT COUNT(*) AS student_count
FROM students;
```

``` sql
SELECT AVG(score) AS average_score,
       MAX(score) AS highest_score,
       MIN(score) AS lowest_score
FROM students;
```

聚合函数通常忽略列中的 `NULL`（`COUNT(*)` 统计行数，不受某一列是否为
`NULL` 影响）。

### 8.2 GROUP BY：分组统计

统计每个班级的学生人数：

``` sql
SELECT class_id, COUNT(*) AS student_count
FROM students
GROUP BY class_id;
```

统计每个班级的平均分：

``` sql
SELECT class_id, AVG(score) AS average_score
FROM students
GROUP BY class_id;
```

### 8.3 HAVING：筛选分组

找出平均分不低于 85 的班级：

``` sql
SELECT class_id, AVG(score) AS average_score
FROM students
GROUP BY class_id
HAVING AVG(score) >= 85;
```

### WHERE 与 HAVING 的区别

-   `WHERE`：分组前筛选单条记录。
-   `HAVING`：分组后筛选分组结果，常用于聚合条件。

``` sql
SELECT class_id, AVG(score) AS average_score
FROM students
WHERE age >= 18
GROUP BY class_id
HAVING AVG(score) >= 85;
```

这条语句先筛选年龄至少 18 岁的学生，再按班级分组，最后只保留平均分至少
85 的班级。

## 9. 多表查询与 JOIN

当所需数据分散在多张表中时，可以通过关联列连接它们。

### 9.1 INNER JOIN：内连接

只返回两张表中满足连接条件的记录：

``` sql
SELECT students.name, classes.class_name
FROM students
INNER JOIN classes
    ON students.class_id = classes.id;
```

使用表别名简化语句：

``` sql
SELECT s.name, c.class_name
FROM students AS s
INNER JOIN classes AS c
    ON s.class_id = c.id;
```

`AS` 用于设置别名；表别名在复杂查询中尤其有用。

### 9.2 LEFT JOIN：左连接

返回左表的所有记录；右表找不到匹配项时，右表列会显示为 `NULL`。

``` sql
SELECT s.name, c.class_name
FROM students AS s
LEFT JOIN classes AS c
    ON s.class_id = c.id;
```

例如，`class_id` 为 `NULL` 或没有对应班级的学生仍会出现在结果中。

### 9.3 RIGHT JOIN：右连接

返回右表的所有记录，并尽可能匹配左表：

``` sql
SELECT s.name, c.class_name
FROM students AS s
RIGHT JOIN classes AS c
    ON s.class_id = c.id;
```

并非所有数据库都支持 `RIGHT JOIN`。有时可以通过交换表的位置改写成
`LEFT JOIN`。

### 9.4 CROSS JOIN：交叉连接

返回两张表的笛卡尔积，即左表每行与右表每行组合一次：

``` sql
SELECT s.name, c.class_name
FROM students AS s
CROSS JOIN classes AS c;
```

若左表有 5 行、右表有 3 行，结果通常有 `5 × 3 = 15`
行。除非确实需要所有组合，否则要谨慎使用。

### 9.5 JOIN 的常见注意事项

1.  `ON` 用来指定两张表如何匹配。
2.  连接列通常应具有相同或兼容的数据类型。
3.  一对多关系会让一条左表记录对应多条结果，这是正常现象。
4.  对 `LEFT JOIN` 而言，如果在 `WHERE`
    中筛选右表列，可能会排除右表不匹配的行，从而改变结果。需要保留左表全部记录时，应仔细考虑条件放在
    `ON` 还是 `WHERE`。

## 10. 子查询

子查询是嵌套在另一条 SQL 语句中的查询。

### 10.1 与单个结果比较

查询分数高于全体学生平均分的学生：

``` sql
SELECT name, score
FROM students
WHERE score > (
    SELECT AVG(score)
    FROM students
);
```

括号中的查询先计算平均分，外层查询再筛选学生。

### 10.2 IN 与子查询

查询属于已有班级的学生：

``` sql
SELECT name
FROM students
WHERE class_id IN (
    SELECT id
    FROM classes
);
```

### 10.3 EXISTS

`EXISTS` 用于判断子查询是否至少返回一行：

``` sql
SELECT c.class_name
FROM classes AS c
WHERE EXISTS (
    SELECT 1
    FROM students AS s
    WHERE s.class_id = c.id
);
```

这条语句找出至少有一名学生的班级。`SELECT 1`
是常见写法，因为这里关心的是"是否存在"，而不是具体返回哪一列。

## 11. 约束与索引

### 11.1 常见约束

  约束            含义
  --------------- ----------------------------------------------------
  `PRIMARY KEY`   主键，唯一标识一行，不能为 `NULL`
  `FOREIGN KEY`   外键，约束表之间的引用关系
  `UNIQUE`        要求值满足唯一性规则；`NULL` 的处理依数据库而异
  `NOT NULL`      不允许该列为 `NULL`
  `DEFAULT`       未指定值时使用默认值
  `CHECK`         要求数据满足指定条件；具体支持行为依数据库版本而异

建表示例：

``` sql
CREATE TABLE classes (
    id INT PRIMARY KEY,
    class_name VARCHAR(50) NOT NULL UNIQUE
);
```

带外键的建表示例：

``` sql
CREATE TABLE students (
    id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    class_id INT,
    score DECIMAL(5, 2),
    FOREIGN KEY (class_id) REFERENCES classes(id),
    CHECK (score >= 0 AND score <= 100)
);
```

这里的 `CHECK`
用于限制分数范围。实际使用前应确认所用数据库版本对该约束的支持情况。

### 11.2 自增主键

MySQL 常见写法：

``` sql
CREATE TABLE students (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL
);
```

插入时可以不提供 `id`：

``` sql
INSERT INTO students (name)
VALUES ('Li');
```

自增语法在不同数据库中有区别，例如 PostgreSQL 常使用 identity 列，SQLite
也有自己的写法。

### 11.3 创建索引

``` sql
CREATE INDEX idx_students_name
ON students(name);
```

唯一索引：

``` sql
CREATE UNIQUE INDEX idx_classes_name
ON classes(class_name);
```

删除索引的语法依数据库而异。MySQL 示例：

``` sql
DROP INDEX idx_students_name ON students;
```

索引的作用与取舍：

-   **优点：** 可能加快查询、排序和连接。
-   **代价：** 占用存储空间，并增加插入、更新、删除时维护索引的开销。
-   **建议：** 优先考虑经常用于 `WHERE`、`JOIN`
    和排序的列；不要给每一列都盲目建索引。
-   **复合索引：** `(a, b)` 这样的索引通常更适合从 `a`
    开始匹配的查询；具体效果应通过执行计划和实际数据验证。

## 12. 视图

视图（VIEW）可以理解为保存下来的查询定义，查询视图时会按其定义读取数据。普通视图通常不单独保存一份查询结果数据；物化视图等机制则不同。

创建视图：

``` sql
CREATE VIEW high_score_students AS
SELECT id, name, score
FROM students
WHERE score >= 90;
```

查询视图：

``` sql
SELECT *
FROM high_score_students;
```

删除视图：

``` sql
DROP VIEW high_score_students;
```

视图可以简化复杂查询、限制对外展示的列，但不应自动被视为完整的安全边界；权限仍需正确配置。

## 13. 事务

事务用于将多个数据库操作作为一个整体管理。常见的 ACID
特性包括原子性、一致性、隔离性和持久性，具体保证程度与数据库和配置有关。

### 13.1 COMMIT 与 ROLLBACK

``` sql
START TRANSACTION;

UPDATE accounts
SET balance = balance - 100
WHERE id = 1;

UPDATE accounts
SET balance = balance + 100
WHERE id = 2;

COMMIT;
```

如果确认操作不应保留，可以在提交前回滚：

``` sql
ROLLBACK;
```

注意：

-   开启事务的语法因数据库而异，例如有的系统使用 `BEGIN`。
-   并非所有语句都能在所有数据库中通过事务回滚。
-   某些 DDL 操作可能隐式提交事务。
-   实际转账场景还应检查账户是否存在、余额是否足够、更新行数是否符合预期，并处理并发问题。

### 13.2 SAVEPOINT：保存点

``` sql
START TRANSACTION;

UPDATE students
SET score = 90
WHERE id = 1;

SAVEPOINT after_first_update;

UPDATE students
SET score = 80
WHERE id = 2;

ROLLBACK TO SAVEPOINT after_first_update;

COMMIT;
```

此例回滚到保存点后，第二次更新被撤销，第一次更新仍可提交。保存点语法和行为需以具体数据库为准。

## 14. 常用函数

不同数据库的函数名、参数和返回类型可能不同。以下为常见写法。

### 14.1 字符串函数

``` sql
SELECT UPPER(name) FROM students;       -- 转大写
SELECT LOWER(name) FROM students;       -- 转小写
SELECT LENGTH(name) FROM students;      -- 长度；多字节字符的计算规则因数据库而异
```

MySQL 常见字符串函数：

``` sql
SELECT CONCAT(name, '_student')
FROM students;
```

### 14.2 数值函数

``` sql
SELECT ROUND(89.567, 2);  -- 四舍五入到 2 位小数
SELECT ABS(-10);          -- 绝对值
SELECT MOD(10, 3);        -- 取余，部分数据库也支持 %
```

### 14.3 日期时间函数

日期时间函数的方言差异较大。MySQL 示例：

``` sql
SELECT CURRENT_DATE();
SELECT CURRENT_TIMESTAMP();
SELECT YEAR('2026-10-25');
SELECT MONTH('2026-10-25');
```

如果要对日期做加减运算，请查阅所用数据库的日期函数，例如 MySQL 的
`DATE_ADD` 与 PostgreSQL 的日期/区间运算写法并不相同。

### 14.4 COALESCE：处理 NULL

``` sql
SELECT name, COALESCE(class_id, 0) AS class_id
FROM students;
```

`COALESCE(a, b, c, ...)` 返回参数中第一个非 `NULL`
的值。示例把缺失的班级编号显示为 `0`，但这只是展示处理；实际业务中应确保
`0` 不会被误认为真实班级编号。

### 14.5 NULLIF

``` sql
SELECT NULLIF(score, 0)
FROM students;
```

`NULLIF(a, b)`：当 `a = b` 时返回 `NULL`，否则返回
`a`。它可以用于避免某些除零场景，但实际表达式仍需考虑 `NULL`
和数据范围。

## 15. CASE 条件表达式

`CASE` 可以在查询中根据条件生成不同结果。

``` sql
SELECT name, score,
       CASE
           WHEN score >= 90 THEN 'Excellent'
           WHEN score >= 80 THEN 'Good'
           WHEN score >= 60 THEN 'Pass'
           ELSE 'Fail'
       END AS grade
FROM students;
```

执行逻辑是从上到下判断 `WHEN`，遇到第一个成立的条件就返回对应的 `THEN`
结果；如果都不成立，则使用 `ELSE`。如果省略 `ELSE`，没有匹配项时通常返回
`NULL`。

## 16. WITH 公用表表达式（CTE）

CTE 可以给一段查询结果起一个临时名称，让复杂 SQL 更容易阅读。

``` sql
WITH class_average AS (
    SELECT class_id, AVG(score) AS avg_score
    FROM students
    GROUP BY class_id
)
SELECT *
FROM class_average
WHERE avg_score >= 85;
```

可以把它理解为：先定义 `class_average`
这段查询，再在后续语句中引用它。CTE
的可用性、递归语法和优化方式因数据库而异。

## 17. 常见易错点

### 17.1 忘记写 WHERE

``` sql
UPDATE students SET score = 0;
DELETE FROM students;
```

这两条语句分别会更新或删除所有行。操作前应先确认目标范围。

### 17.2 用 = NULL

错误：

``` sql
WHERE class_id = NULL
```

正确：

``` sql
WHERE class_id IS NULL
```

### 17.3 混淆 WHERE 和 HAVING

-   `WHERE` 筛选原始行。
-   `HAVING` 筛选分组后的结果，适合使用 `COUNT`、`AVG` 等聚合条件。

### 17.4 忘记 JOIN 条件

``` sql
SELECT *
FROM students
JOIN classes;
```

如果没有连接条件且数据库允许该写法，可能产生笛卡尔积，导致结果行数异常。通常应明确写出
`ON` 条件。

### 17.5 认为查询结果天然有顺序

没有 `ORDER BY`
时，不应依赖数据库返回记录的顺序。需要稳定顺序时，应明确指定排序列。

### 17.6 使用 SELECT \*

`SELECT *`
适合临时查看数据；在正式代码中，明确写出所需列通常更清晰，也能减少表结构变化带来的影响。

### 17.7 拼接用户输入构造 SQL

不要把未经处理的用户输入直接拼接进 SQL 字符串，这可能导致 SQL
注入。应用程序应优先使用参数化查询或预编译语句。

伪代码示意：

``` text
SELECT * FROM students WHERE id = ?
```

实际参数绑定方式取决于所用语言和数据库驱动。

## 18. 速查表

  需求         常用 SQL
  ------------ --------------------------------
  查询数据     `SELECT ... FROM ...`
  条件筛选     `WHERE ...`
  去重         `DISTINCT`
  排序         `ORDER BY ... ASC/DESC`
  限制条数     `LIMIT n`（依数据库而异）
  新增数据     `INSERT INTO ... VALUES ...`
  修改数据     `UPDATE ... SET ... WHERE ...`
  删除记录     `DELETE FROM ... WHERE ...`
  判断空值     `IS NULL` / `IS NOT NULL`
  范围查询     `BETWEEN ... AND ...`
  多值匹配     `IN (...)`
  模糊匹配     `LIKE '%...%'`
  分组统计     `GROUP BY ...`
  分组筛选     `HAVING ...`
  内连接       `INNER JOIN ... ON ...`
  左连接       `LEFT JOIN ... ON ...`
  创建表       `CREATE TABLE ...`
  修改表结构   `ALTER TABLE ...`
  创建索引     `CREATE INDEX ...`
  开始事务     `START TRANSACTION` / `BEGIN`
  提交事务     `COMMIT`
  回滚事务     `ROLLBACK`

------------------------------------------------------------------------

## 推荐学习顺序

1.  先掌握 `SELECT`、`WHERE`、`ORDER BY`、`LIMIT`。
2.  再学习 `INSERT`、`UPDATE`、`DELETE`，特别注意 `WHERE`。
3.  学习 `COUNT`、`SUM`、`AVG`、`GROUP BY` 和 `HAVING`。
4.  重点练习 `INNER JOIN` 与 `LEFT JOIN`。
5.  进一步学习子查询、CTE、索引和事务。
6.  最后结合实际数据库练习执行计划、约束设计与性能优化。

**练习建议：**
对每条查询，先用一句话说明"要从哪张表取什么数据、筛选什么条件、如何排序或汇总"，再写
SQL。这样更容易定位错误。
