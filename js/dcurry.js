module.exports = fun => {
    if(fun instanceof Function) {
        const arity = fun.length

        if(arity > 0) {
            const curried = []
            const apply = (...args) => {
                curried.concat(args)
                return curried.length >= arity ? fun(...curried) : apply
            }

            return apply
        }
        else {
            return fun
        }
    }
    else {
        return null
    }
}
