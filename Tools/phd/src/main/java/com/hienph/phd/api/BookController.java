package com.hienph.phd.api;


import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.concurrent.atomic.AtomicLong;

@RestController
class BookController {
  private static final String template  = "Hello, %s!";
  private final AtomicLong counter = new AtomicLong();

  @GetMapping("/books")
  public Book findAll(@RequestParam(value="name", defaultValue="world") String name) {
    return new Book(counter.incrementAndGet(), String.format(template, name));
  }

  @GetMapping("/books/{bookId}")
  public Book findDetail(
    @PathVariable String bookId,
    @RequestParam(value="name", defaultValue = "aa") String name
  ) {
    return new Book(Long.parseLong(bookId), String.format(template, name));
  }
}
