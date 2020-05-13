-- 1
SELECT CONCAT(first_name, last_name) || ' castiga ' || salary || ' lunar dar doreste ' || 3*salary  "Salariu ideal"
FROM employees;

-- 2
SELECT INITCAP(first_name) "Prenume", UPPER(last_name) "Nume de familie", LENGTH(last_name) "Lungimea numelui"
FROM employees
WHERE last_name LIKE 'J%' OR last_name LIKE 'M%' OR UPPER(SUBSTR(last_name, 3, 1)) = 'A'
ORDER BY "Lungimea numelui";

-- 3
SELECT employee_id, last_name
FROM employees
WHERE LTRIM(RTRIM(UPPER(first_name))) = 'STEVEN';

-- 4
SELECT employee_id "ID",
        last_name "Nume de familie",
        LENGTH(last_name) "Lungimea numelui",
        INSTR(UPPER(last_name), 'A') "Pozitia lui A"
FROM employees
WHERE SUBSTR(LOWER(last_name), -1) = 'e';

-- 5
SELECT last_name, hire_date
FROM employees
WHERE MOD(round(hire_date - sysdate), 7) = 0;

-- 6
SELECT employee_id, last_name, salary, round(1.15 * salary, 2) "Salariu nou", round(1.15 * salary / 100, 2) "Numar sute"
FROM employees
WHERE MOD(salary, 1000) != 0;

-- 7
SELECT last_name, RPAD(hire_date, 20, 'X')
FROM employees
WHERE commission_pct IS NOT NULL;

-- 8
SELECT TO_CHAR(SYSDATE+30, 'MONTH DD YYYY HH24:MI:SS') "Data"
FROM DUAL;

-- 9
SELECT ROUND(TO_DATE('31-12-2020', 'DD-MM-YYYY') - SYSDATE)
FROM dual;

-- 10
SELECT TO_CHAR(SYSDATE+0.5, 'MONTH DD YYYY HH24:MI:SS')
FROM dual;

SELECT TO_CHAR(SYSDATE+5/24/60, 'MONTH DD YYYY HH24:MI:SS')
FROM dual;

-- 11
SELECT CONCAT(last_name, first_name), hire_date, NEXT_DAY(ADD_MONTHS(hire_date, 6), 1)
FROM employees;

-- 13
SELECT last_name, NVL(TO_CHAR(commission_pct), 'Fara comision') "Comision"
FROM employees;

-- 14
SELECT last_name, salary, commission_pct
FROM employees
WHERE salary + NVL(commission_pct, 0) * salary > 10000;

-- 15
SELECT last_name, job_id, salary,
    DECODE(job_id,
        'IT_PROG', salary*1.1,
        'ST_CLERK', salary*1.15,
        'SA_REP', salary*1.2,
        salary) "Salariu renegociat"    -- salary reprezinta "else"
FROM employees;
-- or:
SELECT last_name, job_id, salary,
    CASE job_id WHEN 'IT_PROG' THEN salary*1.1
                WHEN 'ST_CLERK' THEN salary*1.15
                WHEN 'SA_REF' THEN salary*1.2
                ELSE salary
                END "Salariu renegociat"
FROM employees;

-- 16
SELECT last_name, department_name
FROM employees e, departments d
WHERE e.department_id = d.department_id;
-- or
SELECT last_name, department_name
FROM employees e JOIN departments d ON (e.department_id = d.department_id);
-- or
SELECT last_name, department_name
FROM employees JOIN departments USING(department_id);

--17
SELECT e.job_id, j.job_title
FROM employees e, jobs j
WHERE e.department_id = 30 AND e.job_id = j.job_id;

-- 18
SELECT last_name, department_name, location_id
FROM employees e, departments d
WHERE e.department_id = d.department_id (+) AND commission_pct IS NOT NULL;

-- 19
SELECT last_name, job_title, department_name
FROM employees e, jobs j, departments d, locations l
WHERE e.job_id = j.job_id
    AND e.department_id = d.department_id
    AND d.location_id = l.location_id
    AND INITCAP(city) = 'Oxford';
    
-- 20
SELECT ang.employee_id Ang#, ang.last_name Angajat, mgr.employee_id Mgr#, mgr.last_name Manager
FROM employees ang, employees mgr
WHERE ang.manager_id = mgr.employee_id;

-- 21
SELECT ang.employee_id Ang#, ang.last_name Angajat, mgr.employee_id Mgr#, mgr.last_name Manager
FROM employees ang, employees mgr
WHERE ang.manager_id = mgr.employee_id (+);

-- 22
SELECT ang.last_name, ang.department_id, col.last_name
FROM employees ang, employees col
WHERE ang.department_id = col.department_id
    AND ang.employee_id > col.employee_id;

-- 23
SELECT e.last_name, e.job_id, job_title, department_name, salary
FROM employees e, jobs j, departments d
WHERE e.job_id = j.job_id
    AND e.department_id = d.department_id (+);

-- 24
SELECT e.last_name, e.hire_date
FROM employees e, employees Gates
WHERE INITCAP(Gates.last_name) = 'Gates'
    AND e.hire_date > Gates.hire_date;

-- 25
SELECT ang.last_name Angajat, ang.hire_date Data_ang, mgr.last_name Manager, mgr.hire_date Data_mgr
FROM employees ang, employees mgr
WHERE ang.manager_id = mgr.employee_id
    AND ang.hire_date < mgr.hire_date;