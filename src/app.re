module App = {
  [@react.component]
  let make = () =>
    ["Hello world!", "This is React!"]
    ->Belt.List.map(greeting => <h1 key=greeting> greeting->React.string </h1>)
    ->Belt.List.toArray
    ->React.array;
};

ReactDOM.querySelector("#root")
->(
    fun
    | Some(root) => ReactDOM.render(<App />, root)
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
