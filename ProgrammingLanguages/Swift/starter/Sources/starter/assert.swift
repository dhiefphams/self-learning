func assertionAndPrecondition() {
    let age = 10
    // assertions are checked on in debug builds
    // this mean we can used as many assertion as we want
    // without losing the performance
    assert(age >= 0, "A person's age can't be less than zero")
    // for debug purpose
    // assertionFailure("msg") is a friend

    // preconditions are checked in both debug and production builds
    precondition(age >= 0, "A person's age can't be less than zero")
    // preconditionFailure(_:file:line:) to raised the false case of
    // precondition
    // -Ounchecked: preconditions aren't checked
}