// Assembly printf hello, Holberton
hello: .string "Hello, Holberton\n"

      .balign 4                   // must be word aligned
      .global main
main: stp  x29, x30, [sp, -20]!   // allocating 20 bytes
      mov  x29, sp                // Update FP to current SP

      adrp x0, hello              // set 1st argument of printf(format, var1, var2...)
      add  x0, x0, :lo12:hello    // set 1st argument to pass to printf
      bl   printf                 // Call printf()

      // Set up return value of main()
      mov  w0, 0

      ldp  x29, x30, [sp], 20
      ret                  
