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


