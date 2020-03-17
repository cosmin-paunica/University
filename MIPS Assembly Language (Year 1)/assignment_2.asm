# Modify a given array v such that v[i] = sum of the squares of all natural numbers which are less than v[i].

.data
	v: .word 2, 4, 5, -2, 3, 7, 0, 1, 6
	n: .word 9
	space: .asciiz " "
.text
	modifica:
		subu $sp, 4
		sw $fp, 0($sp)
		addi $fp, $sp, 4	# $fp pointeaza zona de variabile de pe stiva
		
		subu $sp, 4
		sw $ra, 0($sp)	# pun $ra pe stiva pentru ca fac apeluri imbricate
		
		subu $sp, 4
		sw $s0, 0($sp)
		
		subu $sp, 4
		sw $s1, 0($sp)
		
		lw $s0, 0($fp)	# v (adresa lui)
		lw $s1, 4($fp)	# n
		
		beqz $s1, exit_modifica	# daca am ajuns la vector de lungime 0, inchei executia procedurii
		
		lw $t0, 0($s0)
		subu $sp, 4
		sw $t0, 0($sp)	# push v[0]
		
		li $v0, 0	# $v0 va deveni suma patratelor, deci il initializez cu 0
		jal suma_patrate
		addu $sp, 4	# golesc stiva dupa terminarea procedurii
		
		sw $v0, 0($s0)	# modific elementul de pe pozitia curenta din vector
		
		addi $s0, 4	# adaug 4 la adresa de memorie a vectorului pentru a obtine adresa urmatorului element
		addi $s1, -1	# scad n
		
		subu $sp, 4
		sw $s1, 0($sp)	# push n
		
		subu $sp, 4
		sw $s0, 0($sp)	# push v (adresa lui)
		
		jal modifica
		addu $sp, 8	# golesc stiva dupa terminarea procedurii
		
		exit_modifica:
			lw $s1, -16($fp)	# restaurez registrii
			lw $s0, -12($fp)	# ---------||---------
			lw $ra, -8($fp)		# ---------||---------
			lw $fp, -4($fp)		# ---------||---------
			addu $sp, 16		# eliberez stiva de registri adaugati pe parcursul procedurii
			jr $ra
	
	suma_patrate:
		subu $sp, 4
		sw $fp, 0($sp)
		addu $fp, $sp, 4	# $fp pointeaza zona de variabile de pe stiva
		
		subu $sp, 4
		sw $ra, 0($sp)	# pun $ra pe stiva pentru ca fac apeluri imbricate
		
		subu $sp, 4
		sw $s0, 0($sp)
		
		lw $s0, 0($fp)	# incarc in $s0 argumentul x (numarul pt. care vreau sa calculez suma)
		addi $s0, -1	# scad 1 pentru a lua in considerare doar numerele strict mai mici ca x
		
		blez $s0, exit_suma_patrate	# daca am ajuns la 0 sau numarul dat ca parametru este negativ, merg la incheierea procedurii
		
		mul $t0, $s0, $s0	# obtin (x-1)**2
		addu $v0, $v0, $t0	# actualizez suma
		
		subu $sp, 4
		sw $s0, 0($sp)	# transmit x-1 ca parametru
		
		jal suma_patrate
		addu $sp, 4	# golesc stiva dupa terminarea procedurii
		
		exit_suma_patrate:
			lw $s0, -12($fp)	# restaurez registrii
			lw $ra, -8($fp)		# ---------||---------
			lw $fp, -4($fp)		# ---------||---------
			addu $sp, 12		# eliberez stiva de registri adaugati pe parcursul procedurii
			jr $ra

main:
	lw $t0, n
	subu $sp, 4
	sw $t0, 0($sp)	# push n
	
	la $t0, v
	subu $sp, 4
	sw $t0, 0($sp)	# push v (adresa lui)
	
	jal modifica
	addu $sp, 8	# golesc stiva dupa terminarea procedurii
	
	lw $t0, n
	li $t1, 0	# index
	li $t2, 0	# index de memorie (din 4 in 4)
	loop_afisare:
		bge $t1, $t0, exit_afisare
		
		lw $a0, v($t2)
		li $v0, 1
		syscall
		
		la $a0, space
		li $v0, 4
		syscall
		
		addi $t1, 1
		addi $t2, 4
		j loop_afisare
	
	exit_afisare:
	li $v0, 10
	syscall