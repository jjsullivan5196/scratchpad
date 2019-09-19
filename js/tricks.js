let iter, gen, p

iter = func => ({
    done: false,
    next() {
        this.value = func(() => { this.done = true })
        return this
    },
    [Symbol.iterator]() { return this }
})

p = 0

gen = iter(done => {
    if(p > 10) {
        done()
    }
    return p++
})

console.log(Array.from(gen))

console.log(JSON.stringify(new Proxy({}, {
    ownKeys() { return ['all', 'this', 'trash'] },
    get(tgt, prop) {
        const member = Reflect.get(tgt, prop)
        if(member instanceof Function) {
            return member
        }
        else {
            return 'get over it'
        }
    }
})))
