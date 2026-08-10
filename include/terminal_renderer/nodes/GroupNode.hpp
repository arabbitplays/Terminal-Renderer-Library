#ifndef TERMINAL_RENDERER_LIBRARY_GROUPNODE_HPP
#define TERMINAL_RENDERER_LIBRARY_GROUPNODE_HPP
#include <algorithm>
#include <terminal_renderer/nodes/RenderNode.hpp>
#include <vector>

namespace TerminalRenderer
{
    class GroupNode : public RenderNode
    {
    public:
        void addChild(RenderNodeHandle child)
        {
            children.push_back(std::move(child));
        }

        void removeChild(const RenderNodeHandle& child)
        {
            children.erase(std::remove(children.begin(), children.end(), child), children.end());
        }

        [[nodiscard]] const std::vector<RenderNodeHandle>& getChildren() const
        {
            return children;
        }

    protected:
        std::vector<RenderNodeHandle> children;
    };

    using GroupHandle = std::shared_ptr<GroupNode>;
} // namespace TerminalRenderer

#endif // TERMINAL_RENDERER_LIBRARY_GROUPNODE_HPP
