const async = require('../build/Release/async');

const runner = (workerId: string, iter: number) => new Promise((resolve, reject) => {
    async.asyncDelay(workerId, iter, false, (err: any, data: any) => {
        return err ? reject(err) : resolve(data);
    });
});

const works = [
    2000000000, 220000000, 250000000, 240000000, 300000000,
    2000000000, 220000000, 250000000, 240000000, 300000000,
    2000000000, 220000000, 250000000, 240000000, 300000000,
];

export const syncDelay = () => {
    works.map(iter => async.syncDelay("Hello", iter, (err: any, data: any) => {
        console.log(err ? err : data);
    }));
};


export const asyncJobs = () => Promise.all(works.map((iter, idx) => {
    return runner(`worker ${idx}`, iter).then(r => console.log(r));
}));


