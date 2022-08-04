.section .text
.globl _start
_start:
movl %esp, %ebp
call main
movl %eax, %ebx
movl $1, %eax
int $0x80
# compound (0x55c799c49990)
# start of "hello"
.globl hello
hello:
pushl %ebp
movl %esp, %ebp
subl $44, %esp

subl $48, %esp
# compound (0x55c799c49d20)
# variable (x)
pushl 8(%ebp)
# call arg
pushl 8(%ebp)
call print
addl $0, %esp
pushl %eax
# variable (y)
pushl 12(%ebp)
# call arg
pushl 12(%ebp)
call print
addl $0, %esp
pushl %eax
# variable (z)
pushl 16(%ebp)
# call arg
pushl 16(%ebp)
call print
addl $0, %esp
pushl %eax
# variable (z)
pushl 16(%ebp)
# variable (y)
pushl 12(%ebp)
# addition
popl %eax
addl (%esp), %eax
addl $4, %esp
pushl %eax
movb (%esp), %cl

# variable (x)
pushl 8(%ebp)
# addition
popl %eax
addl (%esp), %eax
addl $4, %esp
pushl %eax
movb (%esp), %cl


jmp return_statement
# assign default
movl %esp, -0(%ebp)

# start of "main"
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $76, %esp

subl $80, %esp
# compound (0x55c799c4a3e0)
# the first string

subl $24, %esp
movl $0x0, 20(%esp)
movl $0x0a, 16(%esp)
movl $0x0676e6972, 12(%esp)
movl $0x074732074, 8(%esp)
movl $0x073726966, 4(%esp)
movl $0x020656874, 0(%esp)
movl %esp, -36(%ebp)
# assign default
movl %esp, -20(%ebp)

# the second string

subl $24, %esp
movl $0x0, 20(%esp)
movl $0x0a67, 16(%esp)
movl $0x06e697274, 12(%esp)
movl $0x07320646e, 8(%esp)
movl $0x06f636573, 4(%esp)
movl $0x020656874, 0(%esp)
movl %esp, -44(%ebp)
# assign default
movl %esp, -28(%ebp)

# the third string

subl $24, %esp
movl $0x0, 20(%esp)
movl $0x0a, 16(%esp)
movl $0x0676e6972, 12(%esp)
movl $0x074732064, 8(%esp)
movl $0x072696874, 4(%esp)
movl $0x020656874, 0(%esp)
movl %esp, -52(%ebp)
# assign default
movl %esp, -36(%ebp)

# variable (foo)
pushl -20(%ebp)
# variable (bar)
pushl -28(%ebp)
# variable (far)
pushl -36(%ebp)
# call arg
pushl -20(%ebp)
# call arg
pushl -28(%ebp)
# call arg
pushl -36(%ebp)
call hello
addl $0, %esp
pushl %eax
# 

subl $8, %esp
movl $0x0, 4(%esp)
movl $0x0a, 0(%esp)
movl %esp, -56(%ebp)
# call arg
pushl -56(%ebp)
call print
addl $0, %esp
pushl %eax
# Version: 
subl $16, %esp
movl $0x0, 12(%esp)
movl $0x020, 8(%esp)
movl $0x03a6e6f69, 4(%esp)
movl $0x073726556, 0(%esp)
movl %esp, -68(%ebp)
# call arg
pushl -68(%ebp)
call print
addl $0, %esp
pushl %eax
call printVersion
addl $0, %esp
pushl %eax
# 

subl $8, %esp
movl $0x0, 4(%esp)
movl $0x0a, 0(%esp)
movl %esp, -64(%ebp)
# call arg
pushl -64(%ebp)
call print
addl $0, %esp
pushl %eax
# 

subl $8, %esp
movl $0x0, 4(%esp)
movl $0x0a, 0(%esp)
movl %esp, -68(%ebp)
# call arg
pushl -68(%ebp)
call print
addl $0, %esp
pushl %eax
# 

subl $8, %esp
movl $0x0, 4(%esp)
movl $0x0a, 0(%esp)
movl %esp, -72(%ebp)
# call arg
pushl -72(%ebp)
call print
addl $0, %esp
pushl %eax
# integer
pushl $0
movb (%esp), %cl
movl $0, -72(%ebp)

jmp return_statement
# assign default
movl %esp, -4(%ebp)

.data
  version: .ascii  "0.0.2"
  newline: .ascii "\n"

addTwo:
  pushl %ebp
  movl %esp, %ebp
  movl -8(%ebp), %ecx
  popl %ecx
  popl %ebp
  ret

print:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%esp)
  call strlen
  addl $4, %esp
  movl 8(%esp), %ecx
  movl %eax, %edx
  movl $4, %eax
  movl $1, %ebx
  movl %ebp, %esp
  popl %ebp
  int $0x80
  ret


# .type printnl, @function
printnl:
  movl $newline, %ecx # write version string
  movl $1, %edx
  int $0x80
  ret

printVersion:
  movl $4, %eax # use 'write' https://en.wikibooks.org/wiki/X86_Assembly/Interfacing_with_Linux#int_$0x80
  movl $1, %ebx # write to stdout
  movl $version, %ecx # write version string
  movl $5, %edx
  int $0x80
  call printnl
  ret

.type itos, @function
itos:
  pushl %ebp
  movl %esp, %ebp
  movl 12(%esp), %eax           # number
  movl $8, %edi
  leal (%esp, %edi, 1), %ebx   # buffer
  movl $0, %edi                # counter
  movl $0, %esi
  pushl $0x0
  jmp itos_loop 

itos_loop:
  movl $0, %edx
  movl $10, %ecx
  div %ecx
  addl $48, %edx
  pushl %edx
  inc %edi
  test %eax, %eax
  je itos_buffer_loop
  jmp itos_loop

itos_buffer_loop: 
  popl %ecx
  movb %cl, (%ebx, %esi, 1)
  test %edi, %edi
  je itos_end
  inc %esi
  dec %edi
  jmp itos_buffer_loop

itos_end:
  movl %ebx, %eax
  movl %ebp, %esp
  popl %ebp
  ret

return_statement:
 popl %eax
 movl %ebp, %esp
 popl %ebp
 ret

.type strlen, @function
strlen:
  pushl %ebp
  movl %esp, %ebp
  movl $0, %edi
  movl 8(%esp), %eax
  jmp strlenloop

strlenloop:
  movb (%eax, %edi, 1), %cl
  cmpb $0, %cl
  je strlenend
  addl $1, %edi
  jmp strlenloop

strlenend:
  movl %edi, %eax
  movl %ebp, %esp
  popl %ebp
  ret


