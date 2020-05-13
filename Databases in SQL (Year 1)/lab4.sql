-- 2
SELECT MAX(salary) Maxim, MIN(salary) Minim, SUM(salary) Suma, ROUND(AVG(salary)) Media
FROM employees;

-- 3
SELECT job_id, MAX(salary) Maxim, MIN(salary) Minim, SUM(salary) Suma, ROUND(AVG(salary)) Media
FROM employees
GROUP BY job_id
ORDER BY ROUND(AVG(salary)) DESC;

-- 4
SELECT COUNT(employee_id), department_id
FROM employees
GROUP BY department_id;

-- 5
SELECT COUNT(DISTINCT manager_id)
FROM employees;

-- 6
SELECT MAX(salary) - MIN(salary) Diferenta
FROM employees;

-- 7
SELECT department_name, location_id, COUNT(employee_id), ROUND(AVG(salary))
FROM departments NATURAL LEFT JOIN employees
GROUP BY department_id, department_name, location_id;

-- 8
SELECT employee_id, last_name
FROM employees
WHERE salary > (SELECT AVG(salary)
                FROM employees)
ORDER BY salary DESC;

-- 9
SELECT mgr.employee_id Manager, MIN(emp.salary) "Minimum salary"
FROM employees mgr JOIN employees emp ON (mgr.employee_id = emp.manager_id)
WHERE mgr.employee_id is not null
GROUP BY mgr.employee_id
HAVING MIN(emp.salary) >= 1000
ORDER BY MIN(emp.salary);

-- 10
SELECT d.department_id, department_name, MAX(salary)
FROM departments d JOIN employees e ON (d.department_id = e.department_id)
GROUP BY d.department_id, department_name
HAVING MAX(salary) > 3000;

-- 11
SELECT ROUND(MIN(AVG(salary)))
FROM employees
GROUP BY job_id;

-- 12
SELECT ROUND(MAX(AVG(salary)))
FROM employees
GROUP BY department_id;

-- 13: job whose average salary is minimum
SELECT job_id, job_title, AVG(salary)
FROM jobs NATURAL JOIN employees
GROUP BY job_id, job_title
HAVING AVG(salary) = (SELECT MIN(AVG(salary))
                      FROM employees
                      GROUP BY job_id);

-- 14
SELECT ROUND(AVG(salary))
FROM employees
HAVING AVG(salary) > 2500;

-- 15
SELECT department_id, job_id, SUM(salary)
FROM employees
               JOIN jobs USING (job_id)
GROUP BY department_id, job_id;

-- 16: department and no. of employees working in it for:
-- a) departments whose employee count is less than 4
SELECT department_id, department_name, COUNT(employee_id)
FROM departments LEFT JOIN employees USING (department_id)
GROUP BY department_id, department_name
HAVING COUNT(employee_id) < 4;

-- b) department whose no. of employees is maximum
SELECT department_id, department_name, COUNT(employee_id)
FROM departments LEFT JOIN employees USING (department_id)
GROUP BY department_id, department_name
HAVING COUNT(employee_id) = (SELECT MAX(COUNT(*))
                             FROM employees
                             GROUP BY department_id);

-- 17: employees who were hired in the day of the month in which most employees were hired
SELECT employee_id
FROM employees
WHERE TO_CHAR(hire_date, 'DD') = (SELECT TO_CHAR(hire_date, 'DD')
                                  FROM employees
                                  GROUP BY TO_CHAR(hire_date, 'DD')
                                  HAVING COUNT(TO_CHAR(hire_date, 'DD')) = (SELECT MAX(COUNT(TO_CHAR(hire_date, 'DD')))
                                                                            FROM employees
                                                                            GROUP BY TO_CHAR(hire_date, 'DD')));

-- 18: no. of departments where there are at least 15 employees
SELECT COUNT(DISTINCT department_id)
FROM employees
WHERE department_id IN (SELECT department_id
                         FROM employees
                         GROUP BY department_id
                         HAVING COUNT(employee_id) >= 15);

-- 19
SELECT department_id, SUM(salary)
FROM employees
WHERE department_id != 30
GROUP BY department_id
HAVING COUNT(employee_id) > 10
ORDER BY SUM(salary);

-- 20: employees who had at least 2 jobs
SELECT employee_id, last_name
FROM job_history JOIN employees USING (employee_id)
GROUP BY employee_id, last_name
HAVING COUNT(employee_id) >= 2;

-- 21
SELECT AVG(NVL(commission_pct, 0))
FROM employees;

-- 22
SELECT job_id Job, SUM(salary), SUM(DECODE(department_id, 30, salary)) Dep30,
                                SUM(DECODE(department_id, 50, salary)) Dep50
FROM employees e
GROUP BY job_id;

-- 23
SELECT COUNT(employee_id), COUNT(DECODE(TO_CHAR(hire_date, 'YYYY'), '1997', 1)) HiredIn1997
FROM employees;

-- 24
SELECT department_id, department_name, SUM(salary)
FROM departments JOIN employees USING (department_id)
GROUP BY department_id, department_name;
-- or
SELECT d.department_id, d.department_name, a.suma
FROM departments d JOIN (SELECT department_id, SUM(salary) suma
                         FROM employees
                         GROUP BY department_id) a ON (d.department_id = a.department_id);

-- 25: average salary by department for each employee
SELECT last_name, salary, department_id, avgSalary
FROM employees LEFT JOIN (SELECT ROUND(AVG(salary)) avgSalary, department_id
                          FROM employees
                          GROUP BY department_id) USING (department_id);