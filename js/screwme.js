const bytwo = iterable => ({
    next: function() {
        var one, two, rest
        if(iterable.length > 2) {
            [one, two, ...rest] = iterable
            iterable = rest
            return { value: [one, two], done: false }
        }
        else if(iterable.length > 0) {
            const n = { value: [...iterable], done: false }
            iterable = []
            return n
        }
        return { done: true }
    },
    [Symbol.iterator]: function() { return this }
})

const uniqueInOrder=function(iterable){
    return [].concat(Array.from(bytwo(iterable)).filter(v => {
        if(v.length > 1) {
            var [one, two] = v
            if(one == two) {
                return false
            }
            return true
        }
        return true
    }))
}

module.exports = { bytwo, uniqueInOrder }
