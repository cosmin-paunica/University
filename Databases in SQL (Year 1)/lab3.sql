-- 1
-- employees in the same department as Gates, whose name contains the letter 'a'
SELECT ang.last_name, TO_CHAR(ang.hire_date, 'MONTH YYYY')
FROM employees ang JOIN employees Gates USING (department_id)
WHERE INITCAP(Gates.last_name) = 'Gates'
    AND INITCAP(ang.last_name) != 'Gates'
    AND LOWER(ang.last_name) LIKE '%a%';

-- 2
-- employees who have at least one department colleague whose name contains the letter 't'
SELECT e.employee_id, e.last_name, d.department_id, department_name
FROM employees e JOIN departments d ON (e.department_id = d.department_id)
                 JOIN employees t ON (e.department_id = t.department_id)
WHERE LOWER(t.last_name) LIKE '%t%'
GROUP BY e.employee_id, e.last_name, d.department_id, department_name
ORDER BY e.last_name;

-- 3
-- employees whose manager is King
SELECT e.last_name, e.salary, job_title, city, country_name
FROM employees e JOIN jobs j ON (e.job_id = j.job_id)
                 JOIN departments d ON (e.department_id = d.department_id)
                 JOIN locations l ON (l.location_id = d.location_id)
                 JOIN countries c ON (c.country_id = l.country_id)
                 JOIN employees King ON (e.manager_id = King.employee_id)
WHERE INITCAP(King.last_name) = 'King';

-- 4
-- employees from departments whose name contains the string 'ti'
SELECT d.department_id, department_name, last_name, job_id, TO_CHAR(salary, '$99,999.00')
FROM employees e JOIN departments d ON (e.department_id = d.department_id)
WHERE LOWER(d.department_name) LIKE '%ti%'
ORDER BY department_name, last_name;

-- 6
-- departments whose name contains the string 're' or where at least one employee has the job id 'SA_REP'
SELECT department_id
FROM departments
WHERE LOWER(department_name) LIKE '%re%'
UNION
SELECT department_id
FROM employees
WHERE UPPER(job_id) = 'SA_REP';

-- 7
SELECT department_id
FROM departments
WHERE LOWER(department_name) LIKE '%re%'
UNION ALL
SELECT department_id
FROM employees
WHERE UPPER(job_id) = 'SA_REP';

-- 8
-- departments where no one works
SELECT department_id
FROM departments
MINUS
SELECT department_id
FROM employees;
-- or:
SELECT department_id
FROM departments
WHERE department_id NOT IN (SELECT NVL(department_id, 0)
                            FROM employees);

-- 9
-- departments whose name contains the string 're' or in which employees having job id 'HR_REP' work
SELECT department_id
FROM departments
WHERE LOWER(department_name) LIKE '%re%'
INTERSECT
SELECT department_id
FROM employees
WHERE UPPER(job_id) = 'HR_REP';
-- or:
SELECT e.department_id
FROM employees e JOIN departments d ON (e.department_id = d.department_id)
WHERE LOWER(department_name) like '%re%'
    and upper(job_id) = 'HR_REP';

-- 10
-- employees who were hired after Gates
SELECT last_name, hire_date
FROM employees
WHERE hire_date > (SELECT hire_date
                   FROM employees
                   WHERE INITCAP(last_name) = 'Gates');

-- 11
-- employees who are department colleagues of Gates
SELECT last_name, salary
FROM employees
WHERE department_id IN (SELECT department_id
                        FROM employees
                        WHERE INITCAP(last_name) = 'Gates')
    AND INITCAP(last_name) != 'Gates';

-- 12
-- employees whose manager is the president of the company (has no manager)
SELECT last_name, salary
FROM employees
WHERE manager_id = (SELECT employee_id
                    FROM employees
                    WHERE manager_id IS NULL);

-- 13
-- employees whose department_id and salary are the same as the ones of an employee who earns commission
SELECT last_name, department_id, salary
FROM employees
WHERE (department_id, salary) IN (SELECT department_id, salary
                                  FROM employees
                                  WHERE commission_pct IS NOT NULL);

-- 14
-- employees whose salary is greater than average
SELECT employee_id, last_name, salary
FROM employees
WHERE salary > (SELECT AVG(salary)
                FROM employees);

-- 15
-- employees who earn more than any clerk
SELECT last_name, salary * (1 + NVL(commission_pct, 0))
FROM employees
WHERE salary * (1 + NVL(commission_pct, 0)) > ANY (SELECT salary    -- or: > (SELECT MAX(salary) ...
                                                   FROM employees
                                                   WHERE UPPER(job_id) LIKE '%CLERK%')
ORDER BY salary DESC;

-- 16
-- employees who earn no commission, but whose manager does
SELECT last_name, department_name, salary
FROM employees e JOIN departments d USING (department_id)
WHERE commission_pct IS NULL
    AND e.manager_id IN (SELECT employee_id
                         FROM employees
                         WHERE commission_pct IS NOT NULL);
                         
-- 17
-- employees whose salary and commission are the same as the ones of an employee from Oxford
SELECT last_name, department_id, salary, job_id
FROM employees
WHERE (salary, NVL(commission_pct, -1)) IN (SELECT salary, NVL(commission_pct, -1)
                                            FROM employees e JOIN departments d ON (e.department_id = d.department_id)
                                                             JOIN locations l ON (d.location_id = l.location_id)
                                                             WHERE INITCAP(l.city) = 'Oxford');

-- 18
-- employees whose department is located in Toronto
SELECT last_name, department_id, job_id
FROM employees
WHERE department_id IN (SELECT department_id
                        FROM departments NATURAL JOIN locations l
                        WHERE INITCAP(l.city) = 'Toronto');