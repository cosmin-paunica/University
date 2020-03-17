# Encrypt a message via a group isomorphism from (Z_(p-1), +) to (Z_p, *), where p is a prime number.

# Explanations:

# 1)

# Citesc numarul p in registrul $v0. Verific daca e prim, comparand restul impartirii lui la d cu 0, unde d ia valoarea fiecarui numar de la 2 la [p/2]+1. Daca nu este prim, afisez mesajul "Numarul citit nu este prim" si inchei executia programului. Daca este prim, trec mai departe.
# Caut generatorul in felul urmator: pornesc cu g=2 (in registrul $t1). Formez un vector cu puterile sale mod p. Verific daca toate elementele vectorului sunt diferite, comparand element cu element. Daca toate au fost diferite, ies din bucla si avem generatorul g memorat in registrul $t1, precum si vectorul de puteri, retinut in memorie ca v. Daca nu au fost toate diferite, reiau bucla, adaugand 1 la g.
# Afisez pe ecran msggenerator, retinut in memorie, urmat de g ($t1) si de o linie noua (retinuta in memorie ca newline).



# 2)

# Citesc sirul de caractere clar. Parcurg caracter cu caracter, iar pe fiecare il transform in varianta sa criptata, conform vectorului v. La final, elimin caracterul '\n', care, prin criptare, devine alt caracter (acest caracter apare in sirul clar din cauza ca, la citire, mai este un mesaj dedesubt (cel criptat) si in sirul clar se ia si linia noua care le separa). Afisez pe ecran sirul pe care l-am criptat, urmat de o linie noua.



# 3)

# Citesc sirul de caractere criptat.
# Creez un "vector invers" al lui v, retinut in memorie ca w, astfel: daca v[i] = j, atunci w[j] = i. Acest lucru se poate face deoarece toate elementele lui v sunt diferite, avand o functie bijectiva intre indicii vectorului si valorile sale.
# Decriptez sirul in acelasi fel in care l-am criptat pe cel clar, doar ca nu mai elimin ultimul caracter, acesta nemaifiind o problema. Afisez pe ecran sirul pe care l-am criptat.





.data
	v: .space 400
	w: .space 400
	msgprim: .asciiz "Numarul citit nu este prim"
	msggenerator: .asciiz "Generatorul g este: "
	newline: .byte '\n'
	mesajclar: .space 101
	mesajcriptat: .space 101
	sp: .byte ' '
	zerochar: .byte 0
.text
main:
	# 1)
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	# verificare prim
	beq $t0, 1, nuprim
	li $t1, 2   # divizor
	div $t2, $t0, 2
	loopprim:
		bgt $t1, $t2, exitprim   # verific daca d>p/2
		addi $t1, $t1, 1
		
		rem $t3, $t0, $t1
		beqz $t3, nuprim
		addi $t1, $t1, 1
		j loopprim
		
		nuprim:
			la $a0, msgprim
			li $v0, 4
			syscall
			
			li $v0, 10
			syscall
		
	exitprim:
	
	li $t1, 1   # posibil generator (g); pornim de la 1, si nu de la 2, pentru a nu fi nevoie sa decrementam g-ul la iesirea din loopgenerator
	li $t2, 0   # "ok" generator
	loopgenerator:
		beq $t2, 1, exitgenerator
		
		addi $t1, $t1, 1   # incrementarea se face aici pentru a porni de la 2, nu de la 1
		li $t2, 1   # ok = 1
		li $t3, 0   # i
		li $t4, 0   # i memorie
		sw $t2, v($t4)   # v[0] = 1
		
		loopvectorputeri:
			lw $t5, v($t4)
			addi $t3, $t3, 1
			addi $t4, $t4, 4	
			
			bge $t3, $t0, exitvectorputeri
			
			mul $t5, $t5, $t1
			rem $t5, $t5, $t0
			sw $t5, v($t4)   # v[i] = (v[i-1]*g)%p
									
			j loopvectorputeri
		
		exitvectorputeri:
		
		li $t3, 0   # i
		li $t4, 0   # i memorie
		
		addi $t0, $t0, -2   # p = p-2, pentru a putea compara i cu p-2 si j cu p-1
		loopcompararei:
			bge $t3, $t0, exitcompararei
			
			addi $t5, $t3, 1   # j = i + 1
			addi $t6, $t4, 4   # j memorie = i memorie + 1
			
			loopcompararej:		
				bgt $t5, $t0, exitcompararej
				
				lw $t7, v($t4)
				lw $t8, v($t6)
				beq $t7, $t8, okdevinezero
				j continuare
					
				okdevinezero:
					li $t2, 0
				continuare:
				addi $t5, $t5, 1	
				addi $t6, $t6, 4
				j loopcompararej
			
			exitcompararej:
			addi $t3, $t3, 1
			addi $t4, $t4, 4
			j loopcompararei
		
		exitcompararei:
		addi $t0, $t0, 2   # p = p+2, pentru a reveni la p-ul initial
		j loopgenerator	
	
	exitgenerator:
	
	la $a0, msggenerator
	li $v0, 4
	syscall
	move $a0, $t1
	li $v0, 1
	syscall
	la $a0, newline
	li $v0, 4
	syscall
	
	li $t2, 0
	li $t3, 0
	
	
	
	# 2)
	
	la $a0, mesajclar
	li $a1, 100
	li $v0, 8
	syscall
	
	li $t1, 0   # indice (normal si memorie)
	lb $t2, mesajclar($t1)
	loopcriptare:
		beqz $t2, exitcriptare
		
		subu $t2, $t2, 65
		mul $t2, $t2, 4   # pentru a putea accesa elementele lui v de 4 bytes
		lb $t2, v($t2)
		addu $t2, $t2, 65
		sb $t2, mesajclar($t1)
		
		addi $t1, 1
		lb $t2, mesajclar($t1)
		j loopcriptare
	
	exitcriptare:
	
	addi $t1, $t1, -1
	lb $t2, zerochar
	sb $t2, mesajclar($t1)   # elimin caracterul '\n', care, prin criptare, era transformat in 'A'
	la $a0, mesajclar
	li $v0, 4
	syscall
	lb $a0, newline
	li $v0, 11
	syscall
	
	
	
	# 3)
	
	la $a0, mesajcriptat
	li $a1, 100
	li $v0, 8
	syscall
	
	li $t1, 0   # indice
	li $t2, 0   # indice memorie
	addi $t0, $t0, -1   # p = p-1, pentru a putea compara indicele cu p-1
	loopvectorinvers:
		bge $t1, $t0, exitvectorinvers
		
		lw $t3, v($t2)
		mul $t3, $t3, 4
		sw $t1, w($t3)
		
		addi $t1, 1
		addi $t2, 4
		j loopvectorinvers
	
	exitvectorinvers:
	
	li $t1, 0   # indice (normal si memorie)
	lb $t2, mesajcriptat($t1)
	loopdecriptare:
		beqz $t2, exitdecriptare
		
		subu $t2, $t2, 65
		mul $t2, $t2, 4   # pentru a putea accesa elementele lui w de 4 bytes
		lb $t2, w($t2)
		addu $t2, $t2, 65
		sb $t2, mesajcriptat($t1)
		
		addi $t1, 1
		lb $t2, mesajcriptat($t1)
		j loopdecriptare
	
	exitdecriptare:
	
	la $a0, mesajcriptat
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall





# Exemplul 1:

# Input:		Output:

# 29			Generatorul g este: 2
# FMI			DHY
# XOYCXE		UNIBUC



# Exemplul 2:

# Input:		Output:

# 7			Generatorul g este: 3
# ABCD		BDCG
# GFED		DFEB



# Exemplul 3:

# Input:		Output:

# 10			Numarul citit nu este prim
# ABCD
# GFED