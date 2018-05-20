const express = require('express');
import { asyncJobs, syncDelay } from "./async";

const app = express();

app.get('/sync', (req: any, resp: any) => {
    syncDelay();
    resp.json({ done: 'done '});
});

app.get('/async', async (req: any, resp: any) => {
    await asyncJobs();
    resp.json({ done: 'done '});
});

app.get('/', (req: any, resp: any) => {
    resp.json({ hello: 'world' });
});

app.listen(3000);
