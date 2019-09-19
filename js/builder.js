let search, myquery

search = func => {
    const nest = (f, handler) => {
        const root = {}
        const { proxy, revoke } = Proxy.revocable(root, handler)

        f(proxy)
        revoke()

        return root
    }

    const builder = {
        get(tgt, prop, recv) {
            return val => {
                tgt[prop] = val instanceof Function ? nest(val, this) : (val || {})
                return recv
            }
        }
    }

    return nest(func, builder)
}

myquery = b => b.query(q => q.match({ title: 'test'}))

console.log(JSON.stringify(search(myquery)))
