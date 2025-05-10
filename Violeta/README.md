# push_swap

`push_swap` es un proyecto de 42 que consiste en ordenar una lista de números enteros utilizando únicamente un conjunto limitado de instrucciones y dos pilas (stack `a` y stack `b`). El objetivo es realizar el menor número de operaciones posibles para dejar la pila `a` ordenada en orden ascendente.

## Objetivo

Escribir un programa en C llamado `push_swap` que, dado un conjunto de números pasados como argumentos, genere una lista de instrucciones que ordene esos números utilizando exclusivamente operaciones definidas para manipular pilas.

## Instrucciones permitidas

- `sa` / `sb`: intercambia los dos primeros elementos del stack `a` o `b`.
- `ss`: `sa` y `sb` al mismo tiempo.
- `pa` / `pb`: pasa el primer elemento de `b` a `a` o de `a` a `b`.
- `ra` / `rb`: rota todos los elementos del stack `a` o `b` una posición hacia arriba.
- `rr`: `ra` y `rb` al mismo tiempo.
- `rra` / `rrb`: rota todos los elementos del stack `a` o `b` una posición hacia abajo.
- `rrr`: `rra` y `rrb` al mismo tiempo.

## Reglas del proyecto

- No se permite usar funciones estándar de ordenación.
- El programa debe ser eficiente en número de operaciones.
- Debe manejar errores como argumentos no válidos, duplicados o fuera de rango.
- La salida debe consistir únicamente en la secuencia de instrucciones, una por línea.

## Estructura del repositorio

- `srcs/`: código fuente principal.
- `includes/`: cabeceras y módulos auxiliares (`libft`, `gnl`, `printf`, etc.).
- `Makefile`: permite compilar el proyecto fácilmente.
- `push_swap`: binario generado.

## Compilación

```bash
make
```

## Fuentes consultadas
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
