-- 2
DESC employees;
DESC departments;

-- 3
SELECT * FROM employees;
SELECT * FROM departments;

-- 4
SELECT employee_id, last_name, job_id, hire_date
FROM employees;

-- 5
SELECT job_id
FROM employees;

SELECT DISTINCT job_id
FROM employees;

-- 6
SELECT last_name || ', ' || job_id "Angajat si titlu"
FROM employees;

-- 7
SELECT last_name, salary
FROM employees
WHERE salary > 2850;

-- 8
SELECT last_name, department_id
FROM employees
WHERE employee_id = 104;

-- 9
SELECT last_name, salary
FROM employees
WHERE salary NOT BETWEEN 1500 AND 2850;

-- 9.1
SELECT last_name, first_name, salary
FROM employees
WHERE salary BETWEEN 3000 AND 7000;

-- 9.2
SELECT last_name, first_name, salary
FROM employees
WHERE salary >= 3000 AND salary <= 7000;

-- 10
SELECT last_name, job_id, hire_date
FROM employees
WHERE hire_date BETWEEN '20-02-1987' AND '1-05-1989'
ORDER BY hire_date;

-- 11
SELECT last_name, department_id
FROM employees
WHERE department_id IN (10, 30)
ORDER BY last_name;

-- 12
SELECT last_name "Angajat", salary "Salariu lunar"
FROM employees
WHERE salary > 1500 AND department_id IN (10, 30)
ORDER BY last_name;

-- 13
SELECT SYSDATE
FROM dual;

SELECT TO_CHAR(SYSDATE, 'DD/MON/YYYY HH24:MI') "Data si ora"
FROM dual;

-- 14
SELECT last_name, hire_date
FROM employees
WHERE hire_date LIKE '%87';

SELECT last_name, hire_date
FROM employees
WHERE TO_CHAR(hire_date, 'YYYY') = '1987';
-- ghilimelele de la sirul '1987' nu sunt obligatorii

-- 15
SELECT last_name, job_id
FROM employees
WHERE manager_id IS NULL;

-- 16
SELECT last_name, salary, commission_pct
FROM employees
WHERE commission_pct IS NOT NULL
ORDER BY salary DESC, commission_pct DESC;

-- 17
SELECT last_name, salary, commission_pct
FROM employees
ORDER BY salary DESC, commission_pct DESC;
-- valorile NULL sunt plasate primele in ordinea descrescatoare

-- 18
SELECT last_name
FROM employees
WHERE UPPER(last_name) LIKE '__A%';

-- 19
SELECT last_name
FROM employees
WHERE UPPER(last_name) LIKE '%L%L%' AND department_id = 30 OR manager_id = 102;

-- 20
SELECT last_name, job_id, salary
FROM employees
WHERE (upper(job_id) LIKE '%CLERK%'
    OR upper(job_id) LIKE '%REP%')
    AND salary NOT IN (1000, 2000, 3000);