const memo = f => {
    const r = {}
    return (...args) => r[args] || (r[args] = f(...args))
}

const fib = memo(n => n > 1 ? fib(n - 1) + fib(n - 2) : n)

module.exports = {memo, fib}
