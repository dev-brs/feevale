"use client";
import { Button } from "@/components/Button";
import { useState } from "react";

export default function Home() {
  const [text, setText] = useState("");

  return (
    <div className="flex items-center justifcy-center gap-4 w-full h-screen flex-col">
      <h1 className="">Hello World!</h1>
      <input
        className="text-black"
        onChange={(e: any) => setText(e.target.value)}
        value={text}
      ></input>
      <Button intent="primary" size="small" rounded="small">
        Hello World!
      </Button>
    </div>
  );
}
